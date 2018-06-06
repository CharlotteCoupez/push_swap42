/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:15:01 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/23 16:45:39 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_sort_tab(char **argv)
{
	t_info	*lsta;
	t_info	*lstb;
	int		err;

	lsta = NULL;
	lstb = NULL;
	init_struc_list(&lsta);
	init_struc_list(&lstb);
	if (lsta != NULL && lstb != NULL)
	{
		if ((err = create_tab_a(lsta, argv)) > 0 && lsta->len > 1)
		{
			if (lsta->len > 6)
				sort_b(lsta, lstb, 1);
			else
				little_sort(lsta, lstb);
			free_lstint(lsta, lstb);
			return ;
		}
		if (err == -1)
			write(1, "Error\n", 6);
	}
	free_lstint(lsta, lstb);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	else
	{
		argv++;
		if (check_arg(argc, argv))
			handle_sort_tab(argv);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
