#include "push_swap.h"

static void    clean_list(t_dlist *l_start, t_dlist *l_a, t_info *info)
{
    ft_bzero(info->operation, (size_t)info->sum_oper);
    info->sum_oper = 0;
    info->push_a = l_start->size;
    info->push_b = 0;
    info->counter = 0;
    info->i = 0;
    del_list(&l_a);
}

void    try_rotate(t_dlist *l_start, t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int i;

    i = 0;
    while (i < (l_start->size / 2))
    {
        l_a = copy_list(l_start);
        while (info->counter++ < i)
            rotate(l_a, info);
        q_sort(l_a, l_b, info);
        combination(info->operation, info);
        if ((info->sum_oper < info->best_sum) || info->best_sum == 0)
        {
            ft_bzero(info->best_operations, (size_t)info->best_sum);
            info->best_sum = info->sum_oper;
            ft_strcpy(info->best_operations, info->operation);
            clean_list(l_start, l_a, info);
        }
        else
            clean_list(l_start, l_a, info);
        i++;
    }
}

void try_rev_rotate(t_dlist *l_start, t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int i;

    i = 0;
    while (i < (l_start->size / 2))
    {
        l_a = copy_list(l_start);
        while (info->counter++ < i)
            rev_rotate(l_a, info);
        q_sort(l_a, l_b, info);
        combination(info->operation, info);
        if ((info->sum_oper < info->best_sum) || info->best_sum == 0)
        {
            ft_bzero(info->best_operations, (size_t)info->best_sum);
            info->best_sum = info->sum_oper;
            ft_strcpy(info->best_operations, info->operation);
            clean_list(l_start, l_a, info);
        }
        else
            clean_list(l_start, l_a, info);
        i++;
    }
}