/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:59:05 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/06 16:48:28 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			count_nbr(t_lstint *med, t_lstint *cmp, int nbr)
{
	if (cmp->data > med->data && med != cmp)
		nbr++;
	else if (cmp->data < med->data && med != cmp)
		nbr--;
	return (nbr);
}

int			med_placed(t_info *list, t_info *lsta, t_info *lstb, int range)
{
	if (range < list->len / 2)
		while (range)
		{
			if (list->end->type_tab == 'a')
				rr_a(lsta, lstb, 1);
			else
				rr_b(lsta, lstb, 1);
			range--;
		}
	else
		while (range - list->len != 0)
		{
			if (list->end->type_tab == 'a')
				rotate_a(lsta, lstb, 1);
			else
				rotate_b(lsta, lstb, 1);
			range++;
		}
	return (-3);
}

t_lstint	*pivot_choice(t_info *lsta, t_info *lstb, char letter)
{
	int			nbr;
	int			range;
	t_info		*list;
	t_lstint	*med;
	t_lstint	*cmp;

	range = -1;
	list = lsta;
	if (letter == 'b')
		list = lstb;
	med = list->end;
	while (range++ < list->len && range != -2)
	{
		nbr = 0;
		cmp = list->end;
		while (cmp->prev)
		{
			nbr = count_nbr(med, cmp, nbr);
			cmp = cmp->prev;
		}
		if (nbr < 2 && nbr > -2)
			range = med_placed(list, lsta, lstb, range);
		med = med->prev;
	}
	return (list->end);
}
