/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:21:32 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 20:26:19 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_arg(int argc, char **argv)
{
	int i;
	int j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
				j++;
			else
				return(0);
		}
		i++;
	}
	i = 0;
	while(i < argc)
	{
		tmp = argv[i];
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(tmp, argv[j]))
				j++;
			else
				return(0);
		}
		i++;	
	}
	return (1);
}

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
		//printf("tab[%d] %d\n", i, a->data);
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
	int 		i;
	
	MALLCHECK((lsta = (t_info *)malloc(sizeof(t_info))));
	lsta->len = argc - 1;
	lsta->begin = NULL;
	lsta->end = NULL;
	lsta->placed = 0;
	MALLCHECK((lstb = (t_info *)malloc(sizeof(t_info))))	
	lstb->len = 0;
	lstb->begin = NULL;
	lstb->end = NULL;
	lstb->placed = 0;
	if (argc <= 1)
		return (0);
	else
	{

		if (check_arg(argc, argv))
		{
			a = create_tab_a(a, lsta, argv);
			
			//printf("tab cree\n");
			sort_a(lsta, lstb);
			while(lstb->len)
 			{
        		write(1, "pa\n", 3);
        		push_a(lsta, lstb);
    		}
			a = lsta->begin;
			i = 0;
			while (a)
			{
				printf("final data A -%d- -%d-\n", i, a->data);
				i++;
				a = a->next;
			}
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}