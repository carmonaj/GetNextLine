/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:24:33 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:11:44 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	i = 0;
	fresh = NULL;
	if (s)
	{
		fresh = ft_strnew(ft_strlen(s));
		if (fresh == NULL)
			return (NULL);
		while (s[i])
		{
			fresh[i] = (*f)(i, s[i]);
			i++;
		}
		return (fresh);
	}
	return (NULL);
}
