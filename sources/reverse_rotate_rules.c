/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:45:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/06 16:43:13 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr_a(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	if (w)
		write(1, "rra\n", 4);
	(void)(lstb);
	if (lsta->len > 1)
	{
		tmp = lsta->end->prev;
		ft_lstint_pfirst(lsta, lsta->end);
		lsta->end = tmp;
		tmp->next = NULL;
	}
}

void	rr_b(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	if (w)
		write(1, "rrb\n", 4);
	(void)(lsta);
	if (lstb->len > 1)
	{
		tmp = lstb->end->prev;
		ft_lstint_pfirst(lstb, lstb->end);
		lstb->end = tmp;
		tmp->next = NULL;
	}
}

void	rr_ab(t_info *lsta, t_info *lstb, int w)
{
	rr_a(lsta, lstb, w);
	rr_b(lsta, lstb, w);
}
