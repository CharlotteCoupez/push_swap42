/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:46:34 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/22 17:49:42 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (!(need[i]))
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		k = i;
		while (hay[k] == need[j] && k < len)
		{
			k++;
			j++;
			if (need[j] == '\0')
				return ((char *)&hay[i]);
		}
		i++;
	}
	return (0);
}
