#include "push_swap.h"

int         main(int argc, char **argv)
{
    t_dlist *l_a;
    t_dlist *l_b;
    int     i;

    if (argc > 1)
    {
        i = 0;
        l_a = make_list();
        l_b = make_list();
        while (++i < argc)
            push_back_node(l_a, ft_atoi(argv[i]));

        /*----------------------------------------*/
        stupid_sort(l_a);
        put_list(l_a);
        ft_printf("\n");
        put_list(l_b);
        /*----------------------------------------*/
    }
    return (0);
}
