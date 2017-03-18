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
        vivod(info->operation, info); // need to del
        put_list(l_a);                // need to del
        if ((info->sum_oper < info->best_sum) || info->best_sum == 0)
        {
            ft_bzero(info->best_operations, (size_t)info->best_sum);
            info->best_sum = info->sum_oper;
            ft_strcpy(info->best_operations, info->operation);

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
        vivod(info->operation, info); // need to del
        put_list(l_a);                // need to del
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
/*
void    sort_list(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int flag_a;
    int flag_b;

    flag_a = 0;
    flag_b = 0;
    if (l_a->size == 3)
        sort_3_elem_a(l_a, info);
    if(l_b->size == 3)
        sort_3_elem_b(l_b, info);
    if (l_a->head && FIRST_A > SECOND_A)
        swap(l_a, info);
    if (l_b->head && FIRST_B < SECOND_B)
        swap(l_b, info);
    if (!(check_sorted(l_a, info->push_a)))
    {
        rotate(l_a, info);
        flag_a = 1;
    }
    if (!(check_sorted(l_b, info->push_b)))
    {
        rotate(l_b, info);
        flag_b = 1;
    }
    if (l_a->head && FIRST_A > SECOND_A)
        swap(l_a, info);
    if (l_b->head && FIRST_B < SECOND_B)
        swap(l_b, info);
    if (flag_a)
        rev_rotate(l_a, info);
    if (flag_b)
        rev_rotate(l_b, info);
    if (l_a->head && FIRST_A > SECOND_A)
        swap(l_a, info);
    if (l_b->head && FIRST_B < SECOND_B)
        swap(l_b, info);
}
 */