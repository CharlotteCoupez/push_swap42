/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_nocpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:49:55 by ccoupez           #+#    #+#             */
/*   Updated: 2018/02/19 10:28:00 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat_nocpy(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		i++;
	while (j < n)
	{
		if (ft_strchr(s1, s2[j]))
			j++;
		if (j < n)
		{
			s1[i + k] = s2[j];
			j++;
			k++;
		}
	}
	s1[i + j] = '\0';
	return (s1);
}
