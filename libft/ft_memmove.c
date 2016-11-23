/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 17:07:31 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/06 22:44:08 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dp;
	unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (sp > dp)
		ft_memcpy(dp, sp, len);
	else
	{
		while (len--)
			dp[len] = sp[len];
	}
	return (dp);
}
