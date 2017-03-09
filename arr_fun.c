#include "push_swap.h"
/*
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

void    sa(t_intarr *stc)
{
    int tmp;

    if (stc->qty_a > 1)
    {
        tmp = stc->a[0];
        stc->a[0] = stc->a[1];
        stc->a[1] = tmp;
    }
}

void    sb(t_intarr *stc)
{
    int tmp;

    if (stc->qty_b > 1)
    {
        tmp = stc->b[0];
        stc->b[0] = stc->b[1];
        stc->b[1] = tmp;
    }
}

void    ss(t_intarr *stc)
{
    sa(stc);
    sb(stc);
}

void    pa(t_intarr *stc)
{
    int i;

    if (stc->b)
    {
        i = stc->qty_a + 1;
        if
        while (i < stc->qty_a)
            stc->a[i] = stc->a[i - 1];
        stc->a[0] = stc->b[0];
        i = 0;
        while (i < (stc->qty_b - 1))
            stc->b[i] = stc->b[i + 1];
    }

}

void    pb(t_intarr *stc)
{
    int i;

    if (stc->a)
    {
        i = stc->qty_b + 1;
        while (i < stc->qty_b)
            stc->b[i] = stc->b[i - 1];
        stc->b[0] = stc->b[0];
        i = 0;
        while (i < (stc->qty_a - 1))
            stc->a[i] = stc->a[i + 1];
    }

}
*/