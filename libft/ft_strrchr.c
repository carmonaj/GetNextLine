/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:47:48 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/06 22:48:48 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if (s[len] == '\0' && c == '\0')
		return ((char*)&s[len]);
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char*)&s[len]);
	}
	return (0);
}
