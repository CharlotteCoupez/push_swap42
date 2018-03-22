/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstint_pfirst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:50:14 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/07 17:04:04 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "../include/push_swap.h"

void	ft_lstint_pfirst(t_info *dlist, t_lstint *new)
{
	if (dlist->begin == NULL)
	{
		dlist->begin = new;
		dlist->end = new;
	}
	else
	{
		dlist->begin->prev = new;
		new->next = dlist->begin;
		dlist->begin = new;
	}
}