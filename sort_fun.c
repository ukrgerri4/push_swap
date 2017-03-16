#include "push_swap.h"

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
