/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:11:41 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/16 15:27:21 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	while (((char *)s)[i])
		i++;
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (((char *)s)[i])
	{
		str[i] = (*f)(((char *)s)[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
