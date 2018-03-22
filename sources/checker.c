/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:51:25 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 19:30:14 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "../include/push_swap.h"

void	checker(t_lstint *a, t_info *lsta, t_lstint *b, t_info *lstb)
{
	int j;
	int		i;
	char	*line;
	static t_func g_tab[] =
	{
		{&swap_a, "sa"}, {&swap_b, "sb"}, {&swap_ab, "ss"}, {&push_a, "pa"},
		{&push_b, "pb"}, {&rotate_a, "ra"}, {&rotate_b, "rb"}, {&rr_a, "rra"},
		{&rotate_ab, "rr"}, {&rr_b, "rrb"}, {&rr_ab, "rrr"}, {NULL, "\0"}
	};

	//line = NULL;
	while (get_next_line(0, &line))
	{
		i = 0;
		while (ft_strcmp(g_tab[i].rule, line) != 0)// && *g_tab[i].rule != '\0')
		{
			
			i++;
		}
		//printf("g_tab[i].rule %s\n", g_tab[i]	.rule);
		g_tab[i].ptrfunc(lsta, lstb);
		j = 0;
		while (a)
		{
			printf("a[%d] %d\n", j, a->data);
			j++;
			a = a->next;
		}
		j = 0;
		while (b)
		{
			printf("b[%d] %d\n", j, b->data);
			j++;
			b = b->next;
		}
		printf("la %zu lb %zu\n", lsta->len, lstb->len);
		a = lsta->begin;
		b = lstb->begin;
	}
	i = 0;
	while (a->next)
	{
		if (a->data < a->next->data || lstb->len != 0)
		{
			write(1, "KO\n", 3);
			return ;
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
}