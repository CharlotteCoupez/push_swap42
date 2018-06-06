/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:15:04 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/25 09:55:31 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_arg(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if ((argv[i][j] == '-' || argv[i][j] == '+') &&
			ft_isdigit(argv[i][j + 1]))
				j++;
			while (ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] != ' ' && argv[i][j] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_double(t_info *lsta)
{
	t_lstint	*test;
	t_lstint	*tmp;

	test = lsta->begin;
	tmp = lsta->end;
	while (test->next)
	{
		if (tmp->data == test->data)
			return (1);
		test = test->next;
	}
	return (0);
}

int		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (-1);
}

int		create_tab_a(t_info *lsta, char **argv)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	while (*argv)
	{
		j = 0;
		tab = ft_strsplit(*argv, ' ');
		while (tab[j])
		{
			if (ft_atoi(tab[j]) > 2147483647 || ft_atoi(tab[j]) < -2147483648)
				return (free_tab(tab));
			ft_lstint_pback(lsta, ft_lstint_new(ft_atoi(tab[j++])));
			if (++(lsta->len) > 1 && lsta->end->prev->data > lsta->end->data)
				i = 1;
			if (check_double(lsta))
				return (free_tab(tab));
		}
		argv++;
		free_tab(tab);
	}
	if (lsta->len == 0)
		i = -2;
	return (i);
}

void	init_struc_list(t_info **lst)
{
	MALLCHECK(((*lst) = (t_info *)malloc(sizeof(t_info))));
	(*lst)->len = 0;
	(*lst)->placed = 0;
	(*lst)->begin = NULL;
	(*lst)->end = NULL;
}
