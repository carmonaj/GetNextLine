/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 21:18:49 by jcarmona          #+#    #+#             */
/*   Updated: 2016/09/26 23:41:17 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	k = 0;
	if (strlen(little) == 0)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		k = i;
		while (little && little[j] == big[i])
		{
			if ((size_t)j == (ft_strlen(little) - 1))
				return ((char *)&big[i - j]);
			i++;
			j++;
		}
		i = k;
		i++;
	}
	return (NULL);
}
