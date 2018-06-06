/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:06:17 by ccoupez           #+#    #+#             */
/*   Updated: 2018/02/19 10:43:59 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_base(unsigned long long nb, const int base)
{
	size_t len;

	len = 1;
	while (nb)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

char		*ft_ulltoa_base(unsigned long long nb, int base, char maj)
{
	size_t	len;
	char	*tab;

	if (base <= 1)
		return (NULL);
	len = ft_len_base(nb, base);
	tab = ft_strnew(len);
	tab[--len] = '\0';
	if (nb == 0)
	{
		tab[len] = '0';
		return (tab);
	}
	while (len--)
	{
		if (nb % base > 9)
			tab[len] = (nb % base) + (maj ? 'A' : 'a') - 10;
		else
			tab[len] = (nb % base) + '0';
		nb = nb / base;
	}
	return (tab);
}
