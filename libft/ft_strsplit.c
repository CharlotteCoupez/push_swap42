/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:06:42 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/20 15:36:19 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (*s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			nb++;
		i++;
	}
	if (s[i - 1] != c)
		nb++;
	return (nb);
}

static int		ft_size_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		*ft_fill_tab(char const *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		index_str;
	int		index_tab;
	int		nb_word;
	int		len_word;

	if (!s)
		return (NULL);
	tab = NULL;
	nb_word = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	index_str = 0;
	index_tab = 0;
	while (index_tab < nb_word)
	{
		while (s[index_str] == c)
			index_str++;
		len_word = ft_size_word((char *)s + index_str, c);
		tab[index_tab] = ft_fill_tab((char *)s + index_str, len_word);
		index_str += len_word;
		index_tab++;
	}
	tab[index_tab] = NULL;
	return (tab);
}
