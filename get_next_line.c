/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:46:48 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/18 18:46:20 by jcarmona         ###   ########.fr       */
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
			}
		}
		t_tmp = node;
		node = node->next;
	}
	return (s);
}

int		nl_check(char **s, t_list *result, int fd)
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
		if (cpy[++i])
			result->content = ft_strdup(&cpy[i]);
		else
		{
			result->content = 0;
			if (fd == 0)
				return (0);
		}
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	result;
	t_list			*node;
	int				ret;

	if (fd < 0 || !line) 
		return (-1);

	node = ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE);
	if (result.content)
	{
		node->content = ft_strdup(result.content);
		if (nl_check((char**)&node->content, &result, fd))
			if ((*line = build_str(node)))
				return (1);
		ft_lstadd(&node, ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE));
	}
	while ((ret = read(fd, node->content, BUFF_SIZE)) > 0)
	{
		if (nl_check((char**)&node->content, &result, fd))
			if ((*line = build_str(node)))
				return (1);
		ft_lstadd(&node, ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE));
	}
	if (ret < 0)
		return (-1);

	if (node->next)
	{
		*line = build_str(node);
		if (result.content)
			result.content = 0;
		if (node->next)
			node->next = 0;
		return (1);
	}
	else
		*line = 0;
	return (0);
}
