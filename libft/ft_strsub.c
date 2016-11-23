/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:09:41 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:15:01 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*fresh;

	i = 0;
	fresh = NULL;
	if (s)
	{
		if (!(fresh = ft_strnew(len)))
			return (NULL);
		while (len--)
		{
			fresh[i] = s[start];
			i++;
			start++;
		}
		return (fresh);
	}
	return (NULL);
}
