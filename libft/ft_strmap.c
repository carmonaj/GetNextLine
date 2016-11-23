/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:26:51 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:10:42 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	i = 0;
	if (s)
	{
		fresh = ft_strdup(s);
		if (fresh == NULL)
			return (NULL);
		while (s[i])
		{
			fresh[i] = (*f)(s[i]);
			i++;
		}
		return (fresh);
	}
	return (NULL);
}
