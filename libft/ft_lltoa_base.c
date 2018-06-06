/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:12:35 by ccoupez           #+#    #+#             */
/*   Updated: 2018/02/19 10:26:14 by ccoupez          ###   ########.fr       */
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

static char	*check_nb(long long nb, char *tab, size_t len)
{
	if (nb == 0)
	{
		tab[len] = '0';
		return (tab);
	}
	return (tab);
}

char		*ft_lltoa_base(long long nb, const int base)
{
	size_t				len;
	int					sign;
	char				*tab;
	unsigned long long	nbis;

	sign = 0;
	nbis = (unsigned long long)nb;
	if (nb < 0 && base == 10)
	{
		sign = 1;
		nbis = -(unsigned long long)nb;
	}
	len = ft_len_base(nbis, base) + sign;
	tab = ft_strnew(len);
	tab[--len] = '\0';
	tab = check_nb(nb, tab, len);
	while (len--)
	{
		tab[len] = (nbis % base + '0');
		nbis = nbis / base;
	}
	if (sign == 1)
		tab[0] = '-';
	return (tab);
}
