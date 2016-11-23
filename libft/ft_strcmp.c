/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:29:58 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/05 16:02:04 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char*)s1;
	s2p = (unsigned char*)s2;
	i = 0;
	if (ft_strlen((const char*)s1) == 0)
		return (s1p[i] - s2p[i]);
	while (s1p[i] && s2p[i])
	{
		if (s1p[i] == s2p[i])
			i++;
		else
			return ((s1p[i] - s2p[i]));
	}
	return ((s1p[i] - s2p[i]));
}
