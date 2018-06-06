/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:45:29 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/06 16:42:32 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	if (w)
		write(1, "ra\n", 3);
	(void)(lstb);
	if (lsta->len > 1)
	{
		tmp = lsta->begin->next;
		ft_lstint_pback(lsta, lsta->begin);
		lsta->begin = tmp;
		tmp->prev = NULL;
	}
}

void	rotate_b(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	if (w)
		write(1, "rb\n", 3);
	(void)(lsta);
	if (lstb->len > 1)
	{
		tmp = lstb->begin->next;
		ft_lstint_pback(lstb, lstb->begin);
		lstb->begin = tmp;
		tmp->prev = NULL;
	}
}

void	rotate_ab(t_info *lsta, t_info *lstb, int w)
{
	rotate_a(lsta, lstb, w);
	rotate_b(lsta, lstb, w);
}
