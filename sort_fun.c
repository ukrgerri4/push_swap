#include "push_swap.h"

void    q_sort(t_dlist *l_a)
{
    int base;

    base = l_a->tail->nb;
    if (l_a->head->nb > base)
        PB;
    if (l_a->head->nb <= base)
        SS;
}

t_node  *check_order(t_dlist *list)
{
    t_node  *tmp;

    tmp = list->head;
    while (tmp != list->tail)
    {
        if (tmp->nb > tmp->next->nb)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void    stupid_sort(t_dlist *list)
{
    int i = 0;
    t_node  *start;

    start = list->head;
    while ((list->head = check_order(list)))
    {
        swap(list);
        list->head = start;
        i++;
    }
    list->head = start;
    ft_printf("%d\n", i);
}
