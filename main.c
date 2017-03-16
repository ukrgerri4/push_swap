#include "push_swap.h"

void    q_sort(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    if (info->push_a > 3 && !(check_sorted(l_a, info->push_a)))
            separation_a(l_a, l_b, info);
    if (info->push_b > 3 && !(check_sorted(l_b, info->push_b)))
            separation_b(l_a, l_b, info);
    sort_list(l_a, l_b, info); // ??
    joining(l_a, l_b, info);

}


int         main(int argc, char **argv)
{
    t_dlist *l_a;
    t_dlist *l_b;
    t_info  *info;
    int     i;

    g_oper = ft_strnew(100000);
    sum_oper = 0;
    if (argc > 1)
    {
        i = 0;
        l_a = make_list('a');
        l_b = make_list('b');
        while (++i < argc)
            push_back_node(l_a, ft_atoi(argv[i]));
        info = make_info(i - 1);
        q_sort(l_a, l_b, info); // (i - 1) - количество элементов в списке

        /*----------------------------------*/

        vivod(g_oper);
        ft_printf("-------------END------------\n");
        put_list(l_a);
        ft_printf("\n");
        put_list(l_b);
        ft_printf("sum_oper = %d\n", sum_oper);
        ft_printf("-----------------------------\n");

        /*----------------------------------*/

    }
    return (0);
}
