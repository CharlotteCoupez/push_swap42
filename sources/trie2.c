/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:29:49 by ccoupez           #+#    #+#             */
/*   Updated: 2018/03/22 20:23:09 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int partition_a(t_info *lsta, t_info *lstb)
{
    int nb;
    t_lstint *pivot;

    nb = 0;
    pivot = lsta->begin;
    //printf("pivot ;%d\n", pivot->data);
    while (pivot != lsta->end)
    {
        if (pivot->data > lsta->end->data)
        {
            write(1, "pb\n", 3);
            push_b(lsta, lstb);
            nb++;
        }
        else
        {
            write(1, "ra\n", 3);
            rotate_a(lsta, lstb);
        }
    }
    write(1, "pb\n", 3);
    push_b(lsta, lstb);
    nb++;
    //printf("partiton A nombre de push b :%d\n", nb);
    return (nb);
}

int   part_b(t_info *lsta, t_info *lstb,  int nb)
{
    //lsta->len == 1 cest jai partitionner tout a donc le seul qui ;e reste cest
    //le plus grand donc je le cache en dessous de b
    if (lsta->len > 0)
    {
        write(1, "pb\n", 3); //je place mon pivot au sommet de b
        push_b(lsta, lstb);
        write(1, "rb\n", 3); //je cache mon pivot au debut de b
        rotate_b(lsta, lstb);
        lstb->placed++;
    }
    if (nb >= 1)
    {
        write(1, "rb\n", 3); // et je cache lavant dernier pivot juste en dessous du plus grand
        rotate_b(lsta, lstb);
        lstb->placed++;
        nb--;
    }
    return (nb);
}

int sort_b(t_info *lsta, t_info *lstb, int nb)
{
    int tmp_nb;

    tmp_nb = part_b(lsta, lstb, nb);
    //printf("tmp_nb :%d\n", tmp_nb);
    if (lstb->len == lstb->placed)
        return (0);
    if (tmp_nb > 1)
    {
        while (tmp_nb)
        {
            write(1, "pa\n", 3); // et je met la petite partie que jai a trier dans a 
            push_a(lsta, lstb); //pour ensuite rappeler sort a 
            tmp_nb--;
        }
        sort_a(lsta, lstb);
    }
    else if (tmp_nb == 1)
    {
        write(1, "rb\n", 3); // et je cache lavant dernier pivot juste en dessous du plus grand
        rotate_b(lsta, lstb);
        lstb->placed++;
        return (0);
    }
    return (0);
}

int sort_a(t_info *lsta, t_info *lstb)
{
    int nb;

    if (lsta->len <= 1) // && nb < 2)
    {
        return (0);
    }
    nb = partition_a(lsta, lstb);
    //printf("len a :%d\n", lsta->len);
    //print_tab(lsta, lstb);
    sort_a(lsta, lstb);
    //printf("nb :%d\n", nb);
    sort_b(lsta, lstb, nb);
    return (0);
}

/*    int nrb;
    int na;
    t_lstint *pivot;

    nrb = 0;
    na = 1;
    printf("debut partiton B nombre nb quon lui envoie [%d]\n", nb);
    pivot = lstb->end;
    while (nb - 1)
    {
        pivot = pivot->prev;
        nb--;
    }
    printf("pivot :%d\n", pivot->data);
    while (pivot != lstb->end)
    {
        if (pivot->data < lstb->end->data)
        {
            write(1, "pa\n", 3);
            push_a(lsta, lstb);
            na++;
        }
        else if (pivot->data > lstb->end->data)
        {
            print_tab(lsta, lstb);
            write(1, "rb\n", 3);
            rotate_b(lsta, lstb);
            nrb++;
        }
    }
    if (nrb)
    {
        write(1, "pa\n", 3);
        push_a(lsta, lstb);
        na++;
        while (nrb)
        {
            write(1, "rrb\n", 4);
            rr_b(lsta, lstb);
            nrb--;
        }
    }
    printf("partiton B nombre de push A npa[%d]\n", na);
    return (na);*/


/*int sort_a(t_info *lsta, t_info *lstb, int na, int nb)
{
    nb = partition_a(lsta, lstb, na);
    if (lsta->len - lsta->placed < 2) // && nb < 2)
    {
        write(1, "pa\n", 3);
        push_a(lsta, lstb);
        
        if (nb > 1)
        {
            sort_b(lsta, lstb, na, nb);
        }
        
        return (1);
    }
    if (lsta->placed == lsta->len)
        return (1);
    
    printf("len a :%d\n", lsta->len);
    printf("na :%d\n", na);
    printf("na :%d\n", nb);
    print_tab(lsta, lstb);
    sort_a(lsta, lstb, na, nb);
    na++;
    sort_b(lsta, lstb, na, nb);
    
   while(lstb->len)
    {
        write(1, "pa\n", 3);
        push_a(lsta, lstb);
    }
    
}*/