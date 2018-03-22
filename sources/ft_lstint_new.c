/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstint_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:02:47 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/07 16:56:14 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
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
	return (list);
}
