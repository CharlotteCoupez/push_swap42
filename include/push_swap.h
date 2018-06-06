/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:31:17 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/23 15:00:12 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define MALLCHECK(x) if(!x) return ;

typedef struct		s_lstint
{
	int				data;
	char			type_tab;
	struct s_lstint	*next;
	struct s_lstint	*prev;
}					t_lstint;

typedef struct		s_info
{
	int				len;
	int				placed;
	struct s_lstint	*begin;
	struct s_lstint	*end;
}					t_info;

typedef struct		s_rfunc
{
	void			(*ptrfunc) (t_info *lsta, t_info *lstb, int w);
	char			rule[4];
}					t_rfunc;

void				init_struc_list(t_info **lst);
t_lstint			*ft_lstint_new(int content);
void				ft_lstint_pback(t_info *dlist, t_lstint *new);
void				ft_lstint_pfirst(t_info *dlist, t_lstint *new);
int					create_tab_a(t_info *lsta, char **argv);

void				swap_a(t_info *lsta, t_info *lstb, int w);
void				swap_b(t_info *lsta, t_info *lstb, int w);
void				swap_ab(t_info *lsta, t_info *lstb, int w);
void				push_a(t_info *lsta, t_info *lstb, int w);
void				push_b(t_info *lsta, t_info *lstb, int w);
void				rotate_a(t_info *lsta, t_info *lstb, int w);
void				rotate_b(t_info *lsta, t_info *lstb, int w);
void				rotate_ab(t_info *lsta, t_info *lstb, int w);
void				rr_a(t_info *lsta, t_info *lstb, int w);
void				rr_b(t_info *lsta, t_info *lstb, int w);
void				rr_ab(t_info *lsta, t_info *lstb, int w);

void				checker(t_info *lsta, t_info *lstb);
int					check_arg(int argc, char **argv);

void				handle_sort_tab(char **argv);
void				sort_b(t_info *lsta, t_info *lstb, int first);
void				opti_sort(t_info *lsta, t_info *lstb);
int					count_nbr(t_lstint *med, t_lstint *cmp, int nbr);
void				little_sort(t_info *lsta, t_info *lstb);

t_lstint			*pivot_choice(t_info *lsta, t_info *lstb, char letter);

void				free_lstint(t_info *lsta, t_info *lstb);

#endif
