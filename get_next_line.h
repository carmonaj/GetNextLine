/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:47:02 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/22 23:17:23 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft/libft.h"

typedef struct	s_data
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
}				t_data;

int				get_next_line(const int fd, char **line);

#endif
