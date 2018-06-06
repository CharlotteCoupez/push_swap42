/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:00:48 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/23 15:17:26 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lstint	*ft_lstint_new(int content)
{
	t_lstint	*list;

	if (!(list = (t_lstint *)malloc(sizeof(t_lstint))))
		return (NULL);
	if (content)
		list->data = content;
	else
		list->data = 0;
	list->next = NULL;
	list->prev = NULL;
	list->type_tab = 'a';
	return (list);
}

void		ft_lstint_pback(t_info *dlist, t_lstint *new)
{
	if (dlist->begin == NULL)
	{
		dlist->begin = new;
		dlist->end = new;
		new->prev = NULL;
	}
	else
	{
		dlist->end->next = new;
		new->prev = dlist->end;
		dlist->end = new;
	}
	new->next = NULL;
}

void		ft_lstint_pfirst(t_info *dlist, t_lstint *new)
{
	if (dlist->begin == NULL)
	{
		dlist->begin = new;
		dlist->end = new;
		new->next = NULL;
	}
	else
	{
		dlist->begin->prev = new;
		new->next = dlist->begin;
		dlist->begin = new;
	}
}

void		free_maillon(t_lstint **list)
{
	t_lstint *tmp;

	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}

void		free_lstint(t_info *lsta, t_info *lstb)
{
	t_lstint *a;
	t_lstint *b;

	a = NULL;
	b = NULL;
	if (lsta)
		a = lsta->begin;
	if (lstb)
		b = lstb->begin;
	while (a || b)
	{
		if (a)
			free_maillon(&a);
		if (b)
			free_maillon(&b);
	}
	if (lsta)
		free(lsta);
	if (lstb)
		free(lstb);
}
