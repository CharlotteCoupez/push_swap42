/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:51:25 by ccoupez           #+#    #+#             */
/*   Updated: 2018/05/17 14:31:46 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		executed(t_info *lsta, t_info *lstb)
{
	int				i;
	int				j;
	char			*line;
	static t_rfunc	g_tab[] = {
		{&swap_a, "sa"}, {&swap_b, "sb"}, {&swap_ab, "ss"}, {&push_a, "pa"},
		{&push_b, "pb"}, {&rotate_a, "ra"}, {&rotate_b, "rb"}, {&rr_a, "rra"},
		{&rotate_ab, "rr"}, {&rr_b, "rrb"}, {&rr_ab, "rrr"}, {NULL, "\0"}
	};

	j = -1;
	while (get_next_line(0, &line))
	{
		j = 1;
		i = 0;
		while (ft_strcmp(g_tab[i].rule, line) != 0 && *g_tab[i].rule != '\0')
			i++;
		free(line);
		if (g_tab[i].rule[0] != '\0')
			g_tab[i].ptrfunc(lsta, lstb, 0);
		else
			return (0);
	}
	return (j);
}

void	checker(t_info *lsta, t_info *lstb)
{
	t_lstint	*tmp;

	if (executed(lsta, lstb))
	{
		if (lstb->len != 0)
			return (ft_putendl("KO"));
		tmp = lsta->begin;
		while (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				return (ft_putendl("KO"));
			tmp = tmp->next;
		}
		return (ft_putendl("OK"));
	}
	write(1, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	t_info		*lsta;
	t_info		*lstb;
	int			err;

	lsta = NULL;
	lstb = NULL;
	err = 0;
	if (argc <= 1)
		return (0);
	else
	{
		init_struc_list(&lsta);
		init_struc_list(&lstb);
		if (lsta && lstb)
		{
			argv++;
			if (check_arg(argc, argv) && (err = create_tab_a(lsta, argv)) >= 0)
				checker(lsta, lstb);
			else if (err == -1 || !check_arg(argc, argv))
				write(1, "Error\n", 6);
		}
	}
	free_lstint(lsta, lstb);
	return (0);
}
