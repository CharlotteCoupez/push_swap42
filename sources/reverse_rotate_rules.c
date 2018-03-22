/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:25:15 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 09:58:25 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr_a(t_info *lsta, t_info *lstb)
{
	/*int i;
	int tmp;


	i = 0;
	tmp = a[i];
	while(i < (*la) - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[(*la) - 1] = tmp;*/
	t_lstint	*tmp;
	
	(void)(lstb);
	tmp = lsta->begin->next;
	ft_lstint_pback(lsta, lsta->begin);
	lsta->begin = tmp;
	tmp->prev = NULL;
}

void	rr_b(t_info *lsta, t_info *lstb)
{
	/*int i;
	int tmp;


	i = 0;
	tmp = b[i];
	while(i < (*lb) - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[(*lb) - 1] = tmp;*/
	t_lstint	*tmp;

	(void)(lsta);
	if (lstb->len > 1)
	{
		tmp = lstb->begin->next;
		ft_lstint_pback(lstb, lstb->begin);
		lstb->begin = tmp;
		tmp->prev = NULL;
	}
}

void	rr_ab(t_info *lsta, t_info *lstb)
{
	rr_a(lsta, lstb);
	rr_b(lsta, lstb);
}

/*int main()
{
	int b[5] = {5, 26, 5, 1, 10};
	//  int b[0];
	int a[7] = {1, 2, 3, 45, 6, 8, 9};
	printf("1b %d\n", b[0]);
	printf("2b %d\n", b[1]);
	printf("3b %d\n", b[2]);
	printf("4b %d\n", b[3]);
	printf("5b %d\n", b[4]);
	printf("1a %d\n", a[0]);
	printf("2a %d\n", a[1]);
	printf("3a %d\n", a[2]);
	printf("4a %d\n", a[3]);
	printf("5a %d\n", a[4]);
	printf("6a %d\n", a[5]);
	printf("7a %d\n", a[6]);
	printf("aaaaaaa\n");
	reverse_rotate_ab(a, b, 7, 5);
	printf("1b %d\n", b[0]);
	printf("2b %d\n", b[1]);
	printf("3b %d\n", b[2]);
	printf("4b %d\n", b[3]);
	printf("5b %d\n", b[4]);
	printf("1a %d\n", a[0]);
	printf("2a %d\n", a[1]);
	printf("3a %d\n", a[2]);
	printf("4a %d\n", a[3]);
	printf("5a %d\n", a[4]);
	printf("6a %d\n", a[5]);
	printf("7a %d\n", a[6]);
	return(0);
}*/