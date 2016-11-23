/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:31:56 by jcarmona          #+#    #+#             */
/*   Updated: 2016/09/26 23:44:07 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char*)s1;
	s2p = (unsigned char*)s2;
	i = 0;
	while (n--)
	{
		if (s1p[i] != s2p[i])
			return ((s1p[i]) - (s2p[i]));
		i++;
	}
	return (0);
}
