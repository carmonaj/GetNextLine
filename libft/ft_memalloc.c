/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:52:01 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:00:25 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *alloc;

	if (size == 0)
		return (0);
	if (!(alloc = (void *)malloc(size)))
		return (NULL);
	ft_bzero(alloc, size);
	return (alloc);
}
