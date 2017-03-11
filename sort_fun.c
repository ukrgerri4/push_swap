#include "push_swap.h"

void    print_command(t_dlist *src, int i)
{
    if (SWAP)
        ft_printf("s");
    else if (PUSH)
        ft_printf("p");
    else if (ROTATE)
        ft_printf("r");
    else if (REV_ROTATE)
        ft_printf("rr");
    if (src->mark == 'a' && !(PUSH))
        ft_printf("a");
    else if (src->mark == 'a' && PUSH)
        ft_printf("b");
    else if (src->mark == 'b' && !(PUSH))
        ft_printf("b");
    else if (src->mark == 'b' && PUSH)
        ft_printf("a");
    ft_printf("\n");
    sum_oper++;
}

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
