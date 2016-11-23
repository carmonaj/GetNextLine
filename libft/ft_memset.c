/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:12:21 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/03 11:03:17 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bp;

	bp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bp[i] = (unsigned char)c;
		i++;
	}
	return (bp);
}
