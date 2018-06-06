/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_rules.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:52:46 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/13 17:08:41 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	(void)(lstb);
	if (w)
		write(1, "sa\n", 3);
	if (lsta->len <= 2 && lsta->len > 0)
	{
		tmp = lsta->end;
		ft_lstint_pback(lsta, lsta->begin);
		lsta->begin = tmp;
		tmp->prev = NULL;
	}
	else if (lsta->len > 2)
	{
		tmp = lsta->begin->next;
		tmp->next->prev = lsta->begin;
		lsta->begin->next = tmp->next;
		ft_lstint_pfirst(lsta, tmp);
	}
}

void	swap_b(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	(void)(lsta);
	if (w)
		write(1, "sb\n", 3);
	if (lstb->len <= 2 && lstb->len > 0)
	{
		tmp = lstb->end;
		ft_lstint_pback(lstb, lstb->begin);
		lstb->begin = tmp;
		tmp->prev = NULL;
	}
	else if (lstb->len > 2)
	{
		tmp = lstb->begin->next;
		tmp->next->prev = lstb->begin;
		lstb->begin->next = tmp->next;
		ft_lstint_pfirst(lstb, tmp);
	}
}

void	swap_ab(t_info *lsta, t_info *lstb, int w)
{
	swap_a(lsta, lstb, w);
	swap_b(lsta, lstb, w);
}

void	push_a(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	if (w)
		write(1, "pa\n", 3);
	if (lstb->len > 1)
	{
		tmp = lstb->begin->next;
		tmp->prev = NULL;
		ft_lstint_pfirst(lsta, lstb->begin);
		lstb->begin = tmp;
	}
	else if (lstb->len == 1)
	{
		ft_lstint_pfirst(lsta, lstb->begin);
		lstb->begin = NULL;
		lstb->end = NULL;
	}
	if (lstb->len)
	{
		lstb->len--;
		lsta->len++;
		lsta->begin->type_tab = 'a';
	}
}

void	push_b(t_info *lsta, t_info *lstb, int w)
{
	t_lstint	*tmp;

	if (w)
		write(1, "pb\n", 3);
	if (lsta->len > 1)
	{
		tmp = lsta->begin->next;
		tmp->prev = NULL;
		ft_lstint_pfirst(lstb, lsta->begin);
		lsta->begin = tmp;
	}
	else if (lsta->len == 1)
	{
		ft_lstint_pfirst(lstb, lsta->begin);
		lsta->begin = NULL;
		lsta->end = NULL;
	}
	if (lsta->len > 0)
	{
		lsta->len--;
		lstb->len++;
		lstb->begin->type_tab = 'b';
	}
}
