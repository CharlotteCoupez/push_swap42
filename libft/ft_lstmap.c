/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:19:40 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/22 17:02:13 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*lst_new;
	t_list	*begin_list;

	if (!lst && !(*f))
		return (NULL);
	begin_list = f(lst);
	lst_new = begin_list;
	while (lst->next)
	{
		lst = lst->next;
		lst_new->next = f(lst);
		lst_new = lst_new->next;
	}
	return (begin_list);
}
