/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:33:28 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:41:20 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (lst && f)
	{
		head = f(lst);
		new = head;
		lst = lst->next;
		while (lst)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
		new->next = NULL;
	}
	return (head);
}
