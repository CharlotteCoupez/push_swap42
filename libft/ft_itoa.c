/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:45:58 by ccoupez           #+#    #+#             */
/*   Updated: 2018/01/09 19:19:36 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len_int(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		len;
	int		sign;

	len = 1;
	sign = 0;
	len = ft_len_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tab[len--] = '\0';
	while (len >= 0)
	{
		tab[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		tab[0] = '-';
	return (tab);
}
