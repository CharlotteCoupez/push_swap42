/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:09:43 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/23 16:35:29 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_point(char const *s)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	return (i);
}

static size_t	end_point(char const *s, size_t len_str)
{
	while (len_str != 0 && (s[len_str] == ' ' || s[len_str] == '\n' ||
				s[len_str] == '\t'))
		len_str--;
	len_str++;
	return (len_str);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len_str;
	size_t	i;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s) - 1;
	start = start_point(s);
	end = end_point(s, len_str);
	len_str = end - start;
	if (start > end)
		len_str = start - end;
	if (!(str = (char *)malloc(sizeof(*str) * ((len_str) + 1))))
		return (NULL);
	i = 0;
	while (s[start] && start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
