/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 13:02:30 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:01:12 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(link->content = malloc(content_size)))
			return (NULL);
		ft_memcpy((link->content), content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
