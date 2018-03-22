/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstint_pback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:38:09 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/07 18:57:33 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "../include/push_swap.h"

void	ft_lstint_pback(t_info *dlist, t_lstint *new)
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
