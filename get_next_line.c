/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:46:48 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/20 05:54:11 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*build_str(t_list *node)
{
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
			}
		}
		node = node->next;
	}
	return (s);
}

int		nl_check(char **s, t_list *result)
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
		{
			//result->content = ft_strdup(&cpy[i]);
			result->content = ft_strdup(cpy);
			//printf("\n[%s]\n", result->content);
		}
		else
		{
			result->content = 0;
			//printf("its empty\n");
		}
		return (1);
	}
	return (0);
}


int		get_next_line(const int fd, char **line)
{
	static	t_list	result;
	char			buff[BUFF_SIZE+1];
	t_list			*node;
	int				ret;

	ft_memset(buff, 0, BUFF_SIZE+1);

	/* if fd is negative or line pointer is null */
	if (fd < 0 || !line) 
	{
		//printf("error\n");
		return (-1);
	}

	/* create a new node with string of buff_size*/
	node = ft_lstnew(0, 0);

	/* if string exists already */
	if (result.content)
	{
		//printf("<<[%s]>>", result.content);
		//printf("<<%s>>", result.content);
		/* assign the string to the new node */
		node->content = ft_strdup(result.content);
		result.content = 0;
		/* check if there is a newline in this string */
		if (nl_check((char**)&node->content, &result))

			/* if there is, build string & return 1 */
			if ((*line = build_str(node)))
			{
//				printf("(c)");
				return (1);
			}
		/* if there is no newline, create another node and add to the beginning of list */
		//ft_lstadd(&node, ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE));
		ft_lstadd(&node, ft_lstnew(0, 0));
	}

	/* read and allocate a string into the new node */
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		node->content = ft_strdup(buff);
		ft_memset(buff, 0, BUFF_SIZE);
		/*if (ret < BUFF_SIZE)
		{
			*line = build_str(node);
			return (1);
		}*/

		/* check if there is a newline in this string */
		if (nl_check((char**)&node->content, &result) || ret < BUFF_SIZE)

			/* if there is, build string & return 1 */
			if ((*line = build_str(node)))
			{
//				printf("(b)");
				//printf("[[LINE:%s]]\n", *line);
				return (1);
			}

		/* if there is no newline, create another node and add to the beginning of list */
		//ft_lstadd(&node, ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE));
		ft_lstadd(&node, ft_lstnew(0, 0)); 
	}

	/* if you can't read from file/ if invalid */
	if (ret < 0)
	{
		//printf("error\n");
		return (-1);
	}

	if (node->next)
	{
		//printf("LOL\n");
		*line = build_str(node);
//		printf("(a)");
		return (1);
	/*	printf("[result.content:%s]", result.content);
		result.content = 0;
		printf("<foobar>");
		return (0);*/
	}
	
//	printf("(d)");
	return (0);
}
