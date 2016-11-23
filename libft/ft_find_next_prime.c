/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 23:33:51 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 19:00:45 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int count;

	count = 0;
	count = ft_is_prime(nb);
	if (count == 1)
	{
		return (nb);
	}
	else
	{
		return (ft_find_next_prime(nb + 1));
	}
}
