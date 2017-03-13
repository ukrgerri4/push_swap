#include "push_swap.h"

void    q_sort(t_dlist *src, t_dlist *dst, int len)
{
    int pushed;

    if (check_sorted(src, len))
        return ;
    if (len > 3)
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
        sort_list(src, dst, len);
}

void vivod(char *str)
{
    int i;
    int n;
/*
    i = 0;
    while (str[i])
    {
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '3' && str[i - (2 * n + 1)] == '4')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '4' && str[i - (2 * n + 1)] == '3')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        i++;
    }
    */
    i = 0;
    n = 0;
    while (str[i])
    {
        if (str[i] != '0')
        {
            ft_printf("%c", str[i]);
            n++;
        }
        i++;
    }
    ft_printf("\n");
    ft_printf("N = %d\n", n);
}

int         main(int argc, char **argv)
{
    t_dlist *l_a;
    t_dlist *l_b;
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
        q_sort(l_a, l_b, (i - 1)); // (i - 1) - количество элементов в списке
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

