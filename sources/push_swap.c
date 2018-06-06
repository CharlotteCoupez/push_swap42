/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:14:31 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/20 15:14:31 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		first_partition(t_info *lsta, t_info *lstb)
{
	t_lstint	*pivot;

	pivot = pivot_choice(lsta, lstb, 'a');
	while (pivot != lsta->begin)
	{
		if (pivot->data > lsta->begin->data)
			push_b(lsta, lstb, 1);
		else
			rotate_a(lsta, lstb, 1);
	}
	return (lsta->len);
}

int		partition_b(t_info *lsta, t_info *lstb)
{
	int			na;
	t_lstint	*pivot;

	na = 0;
	pivot = pivot_choice(lsta, lstb, 'b');
	while (pivot != lstb->begin)
	{
		if (pivot->data < lstb->begin->data)
		{
			push_a(lsta, lstb, 1);
			na++;
		}
		else
			rotate_b(lsta, lstb, 1);
	}
	push_a(lsta, lstb, 1);
	na++;
	return (na);
}

int		part_a(t_info *lsta, t_info *lstb, int na)
{
	if (lstb->len > 0)
	{
		push_a(lsta, lstb, 1);
		rotate_a(lsta, lstb, 1);
		lsta->placed++;
	}
	if (na >= 1)
	{
		rotate_a(lsta, lstb, 1);
		lsta->placed++;
		na--;
	}
	return (na);
}

void	sort_a(t_info *lsta, t_info *lstb, int na)
{
	int		tmp_na;

	tmp_na = part_a(lsta, lstb, na);
	if (lsta->len == lsta->placed)
		return ;
	if (tmp_na > 1)
	{
		while (tmp_na)
		{
			push_b(lsta, lstb, 1);
			tmp_na--;
		}
		sort_b(lsta, lstb, 0);
	}
	else if (tmp_na == 1)
	{
		rotate_a(lsta, lstb, 1);
		lsta->placed++;
	}
	return ;
}

void	sort_b(t_info *lsta, t_info *lstb, int first)
{
	int		na;

	if (lstb->len <= 35 && !first)
	{
		opti_sort(lsta, lstb);
		return ;
	}
	if (first)
		na = first_partition(lsta, lstb);
	else
		na = partition_b(lsta, lstb);
	sort_b(lsta, lstb, 0);
	sort_a(lsta, lstb, na);
	return ;
}
