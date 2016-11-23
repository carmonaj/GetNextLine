/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:43:47 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:22:17 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		len;
	char	*fresh;

	i = 0;
	len = 0;
	fresh = NULL;
	if (s)
	{
		len = ft_strlen(s);
		while (s[i] && (s[i] == '\t' || s[i] == '\n' ||
					s[i] == '\t' || s[i] == ' '))
			i++;
		if (i == len)
		{
			fresh = ft_strdup("");
			return (fresh);
		}
		while (s[len - 1] && (s[len - 1] == '\t' || s[len - 1] == '\n' ||
					s[len - 1] == '\t' || s[len - 1] == ' '))
			len--;
		if (!(fresh = ft_strsub(s, i, len - i)))
			return (NULL);
	}
	return (fresh);
}
