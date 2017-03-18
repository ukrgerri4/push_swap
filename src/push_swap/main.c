#include "push_swap.h"

void    q_sort(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    if (info->push_a > 3 && !(check_sorted(l_a, info->push_a)))
            separation_a(l_a, l_b, info);
    if (info->push_b > 3 && !(check_sorted(l_b, info->push_b)))
    {
        if (separation_b(l_a, l_b, info))
            return ;
    }
    if (check_sorted(l_a, l_a->size) && l_b->size == 0)
        return ;
    else
    {
        sort_list(l_a, l_b, info);
        joining(l_a, l_b, info);
    }
}


int         main(int argc, char **argv)
{
    t_dlist *l_start;
    t_dlist *l_a;
    t_dlist *l_b;
    t_info  *info;
    int     i;

    if (argc > 1)
    {
        i = 0;
        l_start = make_list('a');
        l_b = make_list('b');
        l_a = 0;
        while (++i < argc)
            push_back_node(l_start, ft_atoi(argv[i]));
        info = make_info(i - 1);
        l_start->size = i - 1;
        try_rotate(l_start, l_a, l_b, info);
        try_rev_rotate(l_start, l_a, l_b, info);
        info->i = -1;
        put_comand(info);
    }
    return (0);
}
