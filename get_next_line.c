/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:46:48 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/16 13:38:53 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include "libft.h"
#include <unistd.h>
#define BUFF_SIZE 1

int		open_file(char *file, int *fd)
{
	if ((*fd = open(file, O_RDONLY)) == -1)
			return (0);
	return (1);
}


int		nl_check(char **s, t_list *result)
{
	char *copy;
	int i;

	i = 0;
	if (strchr(*s, '\n'))
	{
		copy = *s;
		//printf("test: %s\n", *s);
		while ((*s)[i] != '\n')
			i++;
		//printf("--%s--\n", ft_strsub(*s, 0, i));
		*s = ft_strsub(*s, 0, i); 		// <---- got last piece of main str
		//printf("--%s--\n", *s);
		if (copy[++i])
		{
			result->content = &copy[i];
			//printf("TEST: %s\n", result->content);
		}
		else
		{
			result->content = 0;
			//printf("ITS 0\n");
		}

		//while (copy[++i])				// if there is more after the nl, store that in a list for
			//printf("c:%c", copy[i]);	// the next call
		//free(copy);
		//printf("----\n[%s]\n----\n", s);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list 	result;
	int len;
	t_list			*node;
	t_list			*tmp;
	t_list			*copy;

	node = malloc(sizeof(t_list));
	node->next = 0;
	tmp = node;

	*line = "placeholder";
	len = 0;
	
	if(!fd)
		return (0);

	if (result.content)
	{
		node->content = result.content;
		if (nl_check((char**)&node->content, &result))
		{
			while (tmp)
			{
					printf("%s", tmp->content);
					//free(tmp->content);
					copy = tmp;
					tmp = tmp->next;
					//free(copy);
			}
			//free(tmp);
			return (1);
		}
		//printf("NODE: %s\n", node->content);
		node->next = malloc(sizeof(t_list));
		node->next->next = 0;
		node = node->next;

	}
	while ((len = read(fd, (node->content = (ft_strnew(7))), 7)))
	{
		if (nl_check((char**)&node->content, &result))
		{
			break;
		}
		node->next = malloc(sizeof(t_list));
		node->next->next = 0;
		node = node->next;
	}

	while (tmp)
	{
		printf("%s", tmp->content);
		//free(tmp->content);
		copy = tmp;
		tmp = tmp->next;
		//free(copy);
	}
	//free(tmp);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	char line[100];
	char *ptr;

	ptr = line;
	if (argc == 2)
	{
		fd = 0;
		if (!open_file(argv[1], &fd))
			return (-1);
		get_next_line(fd, &ptr);
		printf("\n");
		get_next_line(fd, &ptr);
		printf("\n");
		get_next_line(fd, &ptr);
		//printf("\n");
		//get_next_line(fd, &ptr);
		//printf("\n"); 
		//get_next_line(fd, &ptr);
		close(fd);
	}
	else
		printf("\n");
}
