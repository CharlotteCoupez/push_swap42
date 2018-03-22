/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:49:27 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 09:58:26 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    rotate_a(t_info *lsta, t_info *lstb)
{
	t_lstint    *tmp;

	(void)(lstb);
	if (lsta->len > 1)
	{	
		tmp = lsta->end->prev;
		ft_lstint_pfirst(lsta, lsta->end);
		lsta->end = tmp;
		tmp->next = NULL;
	}

}

void    rotate_b(t_info *lsta, t_info *lstb)
{
	/*int tmp;
	int i;


	i = *lb - 1;
	tmp = b[i];
	while(i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;*/
	t_lstint    *tmp;

	(void)(lsta);
	if (lstb->len > 1)
	{
		tmp = lstb->end->prev;
		ft_lstint_pfirst(lstb, lstb->end);
		lstb->end = tmp;
		tmp->next = NULL;
	}
}

void    rotate_ab(t_info *lsta, t_info *lstb)
{
    rotate_a(lsta, lstb);
    rotate_b(lsta, lstb);
}

/*int main()
// {
	int b[0];// = {5, 26, 5, 1, 10};
	int a[7] = {1, 2, 3, 45, 6, 8, 9};
   // printf("1b %d\n", b[0]);
   // printf("2b %d\n", b[1]);
   // printf("3b %d\n", b[2]);
   // printf("4b %d\n", b[3]);
   // printf("5b %d\n", b[4]);
	printf("1a %d\n", a[0]);
	printf("2a %d\n", a[1]);
	printf("3a %d\n", a[2]);
	printf("4a %d\n", a[3]);
	printf("5a %d\n", a[4]);
	printf("6a %d\n", a[5]);
	printf("7a %d\n", a[6]);
	printf("aaaaaaa\n");
	rotate_a(a, b, 7, 0);
	//printf("1b %d\n", b[0]);
	//printf("2b %d\n", b[1]);
	//printf("3b %d\n", b[2]);
	//printf("4b %d\n", b[3]);
	//printf("5b %d\n", b[4]);
	printf("1a %d\n", a[0]);
	printf("2a %d\n", a[1]);
	printf("3a %d\n", a[2]);
	printf("4a %d\n", a[3]);
	printf("5a %d\n", a[4]);
	printf("6a %d\n", a[5]);
	printf("7a %d\n", a[6]);
	return(0);
}*/