/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:31:17 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 19:35:35 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"

# define MALLCHECK(x) if(!x) return(-1);

typedef struct		s_lstint
{
	int				data;
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

typedef struct		s_func
{
	void			(*ptrfunc) (t_info *lsta, t_info *lstb);
	char			rule[4];
}					t_func;

void		checker(t_lstint *a, t_info *lsta, t_lstint *b, t_info *lstb);

void		swap_a(t_info *lsta, t_info *lstb);
void		swap_b(t_info *lsta, t_info *lstb);
void		swap_ab(t_info *lsta, t_info *lstb);
void		push_a(t_info *lsta, t_info *lstb);
void		push_b(t_info *lsta, t_info *lstb);
void		rotate_a(t_info *lsta, t_info *lstb);
void		rotate_b(t_info *lsta, t_info *lstb);
void		rotate_ab(t_info *lsta, t_info *lstb);
void		rr_a(t_info *lsta, t_info *lstb);
void		rr_b(t_info *lsta, t_info *lstb);
void		rr_ab(t_info *lsta, t_info *lstb);

//int			push_swap(t_lstint *a, t_info *lsta, t_lstint *b, t_info *lstb);
//int 		trie_un(t_info *lsta, t_info *lstb, int na, int nb);
int			sort_a(t_info *lsta, t_info *lstb);


t_lstint	*ft_lstint_new(int content);
void		ft_lstint_pback(t_info *dlist, t_lstint *new);
void		ft_lstint_pfirst(t_info *dlist, t_lstint *new);

void	print_tab(t_info *lsta, t_info *lstb);
void	print_tab_A(t_info *lsta);


#endif