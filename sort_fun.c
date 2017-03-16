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
