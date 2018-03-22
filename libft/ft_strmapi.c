/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:39:50 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/16 15:27:16 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*str;

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
		str[i] = (*f)(i, ((char *)s)[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
