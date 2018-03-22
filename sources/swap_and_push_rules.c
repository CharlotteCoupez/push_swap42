/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_rules.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:52:46 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 09:58:27 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void	swap_a(t_info *lsta, t_info *lstb)
{
	/*int tmp;

	if (*la > 1)
	{
		tmp = a[(*la) - 1];
		a[*la - 1] = a[(*la) - 2];
		a[(*la) - 2] = tmp;
	}*/

	t_lstint	*tmp;

    (void)(lstb);
	if (lsta->len <= 2 )
	{
		tmp = lsta->end;
		ft_lstint_pback(lsta, lsta->begin);
		lsta->begin = tmp;
		tmp->prev = NULL;
	}
	else
	{
		tmp = lsta->end->prev;
		tmp->prev->next = lsta->end;
		lsta->end->prev = tmp->prev;
		ft_lstint_pback(lsta, tmp);
	}	
}

void	swap_b( t_info *lsta, t_info *lstb)
{
	/*int tmp;


	if (*lb > 1)
	{
		tmp = b[(*lb) - 1];
		b[(*lb) - 1] = b[(*lb) - 2];
		b[(*lb) - 2] = tmp;
	}*/
	t_lstint	*tmp;

    (void)(lsta);
	if (lstb->len <= 2)
	{
		tmp = lstb->end;
		ft_lstint_pback(lstb, lstb->begin);
		lstb->begin = tmp;
		tmp->prev = NULL;
	}
	else
	{
		tmp = lstb->end->prev;
		tmp->prev->next = lstb->end;
		lstb->end->prev = tmp->prev;
		ft_lstint_pback(lstb, tmp);
	}			
}

void	swap_ab(t_info *lsta, t_info *lstb)
{
	swap_a(lsta, lstb);
	swap_b(lsta, lstb);
}

void	push_a(t_info *lsta, t_info *lstb)
{
	t_lstint	*tmp;
	if (lstb->len > 1)
	{
		tmp = lstb->end->prev;
		tmp->next = NULL;
		ft_lstint_pback(lsta, lstb->end);
		lstb->end = tmp;

	}
	else
	{
		ft_lstint_pback(lsta, lstb->end);
		lstb->begin = NULL;
		lstb->end = NULL;
	}
	lstb->len--;
	lsta->len++;
}


void	push_b(t_info *lsta, t_info *lstb)
{	
	t_lstint	*tmp;
	if (lsta->len > 1)
	{
		tmp = lsta->end->prev;
		tmp->next = NULL;
		ft_lstint_pback(lstb, lsta->end);
		lsta->end = tmp;
	}
	else
	{
		ft_lstint_pback(lstb, lsta->end);
		lsta->begin = NULL;
		lsta->end = NULL;
	}
	lsta->len--;
	lstb->len++;

}