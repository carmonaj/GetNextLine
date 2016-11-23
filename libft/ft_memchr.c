/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:25:50 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:02:35 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	c2;
	unsigned char	*sp;

	c2 = (unsigned char)c;
	sp = (unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (sp[i] == c2)
			return (&sp[i]);
		i++;
	}
	return (NULL);
}
