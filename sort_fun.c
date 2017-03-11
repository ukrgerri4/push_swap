#include "push_swap.h"

int     find_repetition(t_dlist *src, int len)
{
    t_node *tmp;

    tmp = src->head;
    while (len > 1)
    {
        if (tmp->nb != tmp->next->nb)
            return (1);
        tmp = tmp->next;
        len--;
    }
    return (0);
}

int     check_sorted(t_dlist *src, int len)
{
    t_node *tmp;

    tmp = src->head;
    while (len > 1)
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
        len--;
    }
    return (1);
}

void    q_sort(t_dlist *src, t_dlist *dst, int len)
{
    int pushed;

    if (check_sorted(src, len))
        return ;
    if (len > 2 && find_repetition(src, len))
    {
        if (src->mark == 'a')
            pushed = separation_a(src, dst, len);
        else
            pushed = separation_b(src, dst, len);
        q_sort(src, dst, (len - pushed));
        q_sort(dst, src, pushed);
        joining(dst, src, pushed);
    }
    else
        sort_list(src, len);
}