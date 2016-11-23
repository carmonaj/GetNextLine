/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:24:29 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/06 22:47:21 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = ft_strnew(ft_strlen(s1))))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
