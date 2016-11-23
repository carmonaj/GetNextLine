/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:49:50 by jcarmona          #+#    #+#             */
/*   Updated: 2016/10/07 15:31:40 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**make_fresh(char const *s, char c)
{
	int		i;
	int		words;
	char	**fresh;

	i = 0;
	words = 1;
	fresh = NULL;
	while (s[i++])
	{
		while (s[i] == c && s[i + 1])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i] && s[i + 1])
				i++;
			words++;
		}
	}
	if (!(fresh = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	return (fresh);
}

static char		*null_delimiters(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			s[i] = '\0';
		i++;
	}
	return (s);
}

static char		**fill_fresh(int i, int len, char *temp, char **fresh)
{
	int j;

	j = 0;
	while (i < len)
	{
		if (!temp[i])
			i++;
		else
		{
			if (!(fresh[j] = ft_strdup(&temp[i])))
				return (NULL);
			j++;
			i += ft_strlen(&temp[i]);
		}
	}
	fresh[j] = NULL;
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	char	*temp;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	fresh = NULL;
	len = ft_strlen(s);
	if (!(temp = ft_strdup(s)))
		return (NULL);
	temp = null_delimiters(temp, c);
	if (!(fresh = make_fresh(s, c)))
		return (NULL);
	fresh = fill_fresh(i, len, temp, fresh);
	return (fresh);
}
