/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:46:48 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/22 23:03:49 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				free(node->content);
				free(tmp);
			}
		}
		t_tmp = node;
		node = node->next;
		free(t_tmp);
	}
	return (s);
}

int		nl_check(char **s, t_list *result)
{
	char	*cpy;
	char	*cpy2;
	char	*cpy3;
	int		i;

	i = 0;
	cpy2 = *s;
	if (ft_strchr(*s, '\n'))
	{
		cpy = *s;
		while ((*s)[i] != '\n')
			i++;
		*s = ft_strsub(*s, 0, i);
		if ((ft_strlen(cpy += i + 1)) > 0)
		{
			cpy3 = result->content;
			result->content = ft_strdup(cpy);
			free(cpy3);
		}
		else
			result->content = 0;
		free(cpy2);
		return (1);
	}
	return (0);
}

int		check(char **line, t_list *node, t_list *result, int ret)
{
	char	*tmp;

	tmp = node->content;
	if (nl_check((char**)&node->content, result) || ret < BUFF_SIZE)
	{
		tmp = node->content;
		if ((*line = build_str(node)))
		{
			free(tmp);
			return (1);
		}
	}
	return (0);
}

int		end(char **line, t_list *node, int ret)
{
	if (ret < 0)
		return (-1);
	if (node->next)
	{
		*line = build_str(node);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	result;
	t_list			*node;
	t_data			t_d;

	if (fd < 0 || !line)
		return (-1);
	ft_memset(t_d.buff, 0, BUFF_SIZE + 1);
	node = ft_lstnew(0, 0);
	if (result.content)
	{
		node->content = ft_strdup(result.content);
		result.content = 0;
		if (check(line, node, &result, BUFF_SIZE))
			return (1);
		ft_lstadd(&node, ft_lstnew(0, 0));
	}
	while ((t_d.ret = read(fd, t_d.buff, BUFF_SIZE)) > 0)
	{
		node->content = ft_strdup(t_d.buff);
		ft_memset(t_d.buff, 0, BUFF_SIZE + 1);
		if (check(line, node, &result, t_d.ret))
			return (1);
		ft_lstadd(&node, ft_lstnew(0, 0));
	}
	return (end(line, node, t_d.ret));
}
