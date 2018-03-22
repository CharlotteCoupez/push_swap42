/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:09:20 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 10:31:16 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

void	print_tab(t_info *lsta, t_info *lstb)
{
	t_lstint *a;
	t_lstint *b;

	int i = 0;
	a = lsta->begin;
	while (a)
	{
		printf("data A -%d- -%d-\n", i, a->data);
		i++;
		a = a->next;
	}
	//printf("lstb->len %zu\n", lstb->len);
	if (lstb->len > 0)
	{
		
		b = lstb->begin;
		i = 0;
		while (b)
		{
			printf("        data B -%d- -%d-\n", i, b->data);
			i++;
			b = b->next;
		}
	}
}

void	print_tab_A(t_info *lsta)
{
	t_lstint *a;
	int i = 0;
	a = lsta->begin;
	while (a)
	{
		printf("data A -%d- -%d-\n", i, a->data);
		i++;
		a = a->next;
	}
	//printf("lstb->len %zu\n", lstb->len);
}
