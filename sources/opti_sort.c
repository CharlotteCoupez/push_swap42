/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:15:58 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/06 16:49:28 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	place_smaller(t_info *lsta, t_info *lstb, int range)
{
	if (range > lstb->len / 2)
		while (range - lstb->len != 0)
		{
			rr_b(lsta, lstb, 1);
			range++;
		}
	else
		while (range)
		{
			rotate_b(lsta, lstb, 1);
			range--;
		}
}

int		find_smaller(t_info *lstb)
{
	int			i;
	int			range;
	t_lstint	*smaller;
	t_lstint	*tmp;

	i = 0;
	range = 0;
	smaller = lstb->begin;
	tmp = lstb->begin;
	while (tmp)
	{
		if (smaller->data > tmp->data)
		{
			smaller = tmp;
			range = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (range);
}

void	opti_sort(t_info *lsta, t_info *lstb)
{
	int			range;

	if (lstb->len == 0)
		return ;
	range = find_smaller(lstb);
	place_smaller(lsta, lstb, range);
	push_a(lsta, lstb, 1);
	rotate_a(lsta, lstb, 1);
	opti_sort(lsta, lstb);
}
