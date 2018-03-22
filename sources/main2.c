/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:12:35 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/13 15:13:32 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "../include/push_swap.h"


t_lstint	*create_tab_a(t_lstint *a, t_info *lsta, char **argv)
{
	int i;
	int j;

	i = lsta->len - 1;
	j = 1;

	while (i >= 0)
	{
		a = ft_lstint_new(ft_atoi(argv[j]));
		ft_lstint_pfirst(lsta, a);
		printf("tab[%d] %d\n", i, a->data);
		i--;
		j++;
	}

	return (lsta->begin);
}

int		main(int argc, char **argv)
{
	t_lstint	*a;
	t_info		*lsta;
		t_lstint	*b;
	t_info		*lstb;
	char *line;
	int i;

	line = NULL;
	MALLCHECK((lsta = (t_info *)malloc(sizeof(t_info))));
	lsta->len = argc - 1;
	lsta->begin = NULL;
	lsta->end = NULL;
	MALLCHECK((lstb = (t_info *)malloc(sizeof(t_info))))	
	lstb->len = 0;
	lstb->begin = NULL;
	lstb->end = NULL;
	if (argc <= 1)
		return (0);
	else
	{
		a = create_tab_a(a, lsta, argv);
		printf("tab cree\n");
		checker(a, lsta, b, lstb);
		i = 0;
		//while (j < lsta->len)
		//{
		////	printf("a[%d] %d\n", j, a[j]);
		//	j++;
		//}
	}
	return (0);
}