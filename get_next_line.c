/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:46:48 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/20 21:00:51 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*build_str(t_list *node)
{
	t_list	*t_tmp;
	char	*tmp;
	char	*s;

	s = 0;
	while (node)
	{
		if (node->content)
		{
			if (!s)
				s = ft_strdup(node->content);
			else
			{
				tmp = s;
				s = ft_strjoin(node->content, s);
				free(tmp);
			}
		}
		t_tmp = node;
		node = node->next;
		free(t_tmp);
	}
	return (s);
}


/*int		nl_check(char **s, t_list *result)
{
	char	*cpy;
	int		i;

	i = 0;

	if (ft_strchr(*s, '\n'))
	{
		cpy = *s;
		while ((*s)[i] != '\n')
			i++;
		*s = ft_strsub(*s, 0, i);
		if ((ft_strlen(cpy += i+1)) > 0)
			result->content = ft_strdup(cpy);
		else
			result->content = 0;
		return (1);
		
	}
	return (0);
}*/

int		nl_check(char **s, t_list *result)
{
	char	*cpy;
	char	*cpy2;
	int		i;

	i = 0;
	cpy2 = *s;
	if (ft_strchr(*s, '\n'))
	{
		cpy = *s;
		while ((*s)[i] != '\n')
			i++;

		//printf("[(s):%s]\n", *s);
		*s = ft_strsub(*s, 0, i);

		//printf("[(cpy):%s]\n", cpy);
		//printf("[(s):%s]\n", *s);
		
		if ((ft_strlen(cpy += i+1)) > 0)
		{
			//printf("[(cpy):%s]\n", cpy);
			result->content = ft_strdup(cpy);
	//		printf("[%s:%zu]\n", *s, ft_strlen(*s));
		}
		else
			result->content = 0;
		free(cpy2);
		return (1);
	}
	return (0);
}


int		get_next_line(const int fd, char **line)
{
	static	t_list	result;
	char			buff[BUFF_SIZE+1];
	t_list			*node;
	char			*cpy = 0;
	char			*cpy2;
	int				ret;

	ft_memset(buff, 0, BUFF_SIZE+1);

	/* if fd is negative or line pointer is null */
	if (fd < 0 || !line) 
		return (-1);

	/* create a new node with string of buff_size*/
	node = ft_lstnew(0, 0);

	/* if string exists already */
	if (result.content)
	{
		/* assign the string to the new node */
		node->content = ft_strdup(result.content);
		//printf("[%s:%zu]\n", node->content, ft_strlen(node->content));
		free(result.content);
		result.content = 0;

		cpy = node->content;
		/* check if there is a newline in this string */
		if (nl_check((char**)&node->content, &result))
		{
			cpy = node->content;
			/* if there is, build string & return 1 */
			if ((*line = build_str(node)))
			{
				free(cpy);
				return (1);
			}
		}
		/* if there is no newline, create another node and add to the beginning of list */
		ft_lstadd(&node, ft_lstnew(0, 0));
	}

	/* read and allocate a string into the new node */
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		node->content = ft_strdup(buff);
		ft_memset(buff, 0, BUFF_SIZE+1);

		/* check if there is a newline in this string */
		if (nl_check((char**)&node->content, &result) || ret < BUFF_SIZE)
		{
			cpy2 = node->content;
			//printf("[%s:%zu]\n", node->content, ft_strlen(node->content));
			/* if there is, build string & return 1 */
			if ((*line = build_str(node)))
			{
				free(cpy2);
				return (1);
			}
		}

		/* if there is no newline, create another node and add to the beginning of list */
		ft_lstadd(&node, ft_lstnew(0, 0)); 
	}

	/* if you can't read from file/ if invalid */
	if (ret < 0)
			return (-1);

	if (node->next)
	{
		*line = build_str(node);
		free(cpy);
		return (1);
	}

	free(node->content);
	free(node);
	return (0);
}
