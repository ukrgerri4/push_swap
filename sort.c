#include "push_swap.h"

int     check_sorted(t_dlist *src, int len)
{
    t_node *tmp;
    int     tmp_len;

    tmp = src->head;
    tmp_len = len;
    while (tmp_len > 1)
    {
        if (src->mark == 'a')
        {
            if (tmp->nb > tmp->next->nb)
                return (0);
        }
        else
        {
            if (tmp->nb < tmp->next->nb)
                return (0);
        }
        tmp = tmp->next;
        tmp_len--;
    }
    return (1);
}

void    sort_list(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int flag_a;
    int flag_b;

    flag_a = 0;
    flag_b = 0;
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