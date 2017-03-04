#include "push_swap.h"

void    putarr(t_intarr *stc)
{
    int i = 0;
    while (i < stc->qty_a)
        ft_printf("%d ", stc->a[i++]);
}

t_intarr    *make_stc(int argc)
{
    t_intarr *tmp;

    if (!(tmp = (t_intarr*)malloc(sizeof(t_intarr))))
        return (0);
    tmp->a = (int*)malloc(sizeof(int) * (argc - 1));
    tmp->b = (int*)malloc(sizeof(int) * (argc - 1));
    tmp->qty_all = argc - 1;
    tmp->qty_a = argc - 1;
    tmp->qty_b = 0;
    return (tmp);
}

int         main(int argc, char **argv)
{
    t_intarr *stc;
    int i;

    stc = make_stc(argc);
    i = 0;
    if (argc > 1)
        while (++i < argc)
            stc->a[i - 1] = ft_atoi(argv[i]);
    putarr(stc); // help function
    return (0);
}

