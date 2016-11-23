/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 18:18:54 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/09 00:19:35 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (ft_strlen((char *)lil) == 0)
		return ((char *)big);
	while (big[i] && i < (int)len)
	{
		while (big[i] && lil[j] && lil[j] == big[i] && i < (int)len)
		{
			j++;
			i++;
		}
		if (j == (int)ft_strlen(lil))
			return ((char*)big + i - j);
		else
			i = (i - j) + 1;
		j = 0;
	}
	return (NULL);
}
