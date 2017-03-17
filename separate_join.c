#include "push_swap.h"

int     check_last_pushed_element(t_dlist *src, int median,int len)
{
    t_node *tmp;

    tmp = src->head;
    if (src->mark == 'a')
    {
        while (len > 0) {
            if (tmp->nb < median)
                return (0);
            tmp = tmp->next;
            len--;
        }
    }
    else
    {
        while (len > 0) {
            if (tmp->nb >= median)
                return (0);
            tmp = tmp->next;
            len--;
        }
    }
    return (1);
}

void    separation_a(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int     median;
    int     pushed;
    int     start_b;
    int     i;
    int     j;

    i = 0;
    j = 0;
    start_b = info->push_b;
    pushed = 0;
    median = find_median(l_a, info->push_a);
    while (i < info->push_a)
    {
        if (l_a->head->nb < median)
        {
            push(l_a, l_b, info);
            pushed++;
        }
        else if (!(check_last_pushed_element(l_a, median, (info->push_a - i))))
        {
            rotate(l_a, info);
            j++;
        }
        else
            break ;
        i++;
    }
    while (((info->push_a - pushed) != l_a->size) && j-- > 0)
        rev_rotate(l_a, info);
    info->push_b = pushed;
    info->push_a = info->push_a - info->push_b;
    q_sort(l_a, l_b, info);
    info->push_b = start_b;
}

int    separation_b(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int     median;
    int     pushed;
    int     start_b;
    int     i;
    int     j;

    i = 0;
    j = 0;
    pushed = 0;
    median = find_median(l_b, info->push_b);
    while (i < info->push_b)
    {
        if (l_b->head->nb >= median)
        {
            push(l_b, l_a, info);
            pushed++;
        }
        else if (!(check_last_pushed_element(l_b, median, (info->push_b - i))))
        {
            rotate(l_b, info);
            j++;
        }
        else
            break ;
        i++;
    }
    while (((info->push_b - pushed) != l_b->size) && j-- > 0)
        rev_rotate(l_b, info);
    info->push_a = pushed;
    info->push_b = info->push_b - info->push_a;
    start_b = info->push_b - info->push_a;
    q_sort(l_a, l_b, info);
    if (start_b <= 6)
        return (1);
    return (0);
}

void    joining(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int i;

    i = 0;
    while (i < info->push_b)
    {
        push(l_b, l_a, info);
        i++;
    }
}