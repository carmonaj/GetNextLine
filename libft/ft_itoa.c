/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:20:34 by jcarmona          #+#    #+#             */
/*   Updated: 2016/09/30 23:12:16 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_size(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (size--)
	{
		while (n >= 10)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
			size--;
		}
		str[size] = n + '0';
		break ;
	}
	return (str);
}
