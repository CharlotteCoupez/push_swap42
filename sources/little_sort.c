/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:17:58 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/06 16:49:58 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		place_biggest(t_info *lsta, t_info *lstb, int range)
{
	if (range <= lsta->len / 2)
		while (range)
		{
			rotate_a(lsta, lstb, 1);
			range--;
		}
	else
		while (range - lsta->len != 0)
		{
			rr_a(lsta, lstb, 1);
			range++;
		}
	push_b(lsta, lstb, 1);
	return (-1);
}

void	sort_three(t_info *lsta, t_info *lstb)
{
	int i;

	i = 1;
	while (i > 0)
	{
		i = -1;
		if (lsta->end->data < lsta->end->prev->data)
		{
			rr_a(lsta, lstb, 1);
			i = 1;
		}
		if (lsta->begin->data > lsta->end->data)
		{
			rotate_a(lsta, lstb, 1);
			i = 1;
		}
		if (lsta->begin->data > lsta->begin->next->data)
		{
			swap_a(lsta, lstb, 1);
			i = 1;
		}
	}
	while (lstb->len)
		push_a(lsta, lstb, 1);
}

void	little_sort(t_info *lsta, t_info *lstb)
{
	int			nbr;
	int			range;
	t_lstint	*smaller;
	t_lstint	*cmp;

	range = -1;
	smaller = lsta->begin;
	while (range++ < lsta->len && lsta->len > 3)
	{
		nbr = 0;
		cmp = lsta->begin;
		while (cmp)
		{
			nbr = count_nbr(smaller, cmp, nbr);
			cmp = cmp->next;
		}
		smaller = smaller->next;
		if (nbr == lsta->len - 1)
		{
			range = place_biggest(lsta, lstb, range);
			smaller = lsta->begin;
		}
	}
	sort_three(lsta, lstb);
}
