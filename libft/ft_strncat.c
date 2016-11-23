/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 10:32:52 by jcarmona          #+#    #+#             */
/*   Updated: 2016/09/22 18:16:22 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**why do i need this, why can't i return s1 and not a pointer to it(result)
**this only happens when i use the *xx instead of xx[x]
*/

char*ft_strncat(char *s1, const char *s2, int n)
{
	char *result;

	result = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && n > 0)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (result);
}
