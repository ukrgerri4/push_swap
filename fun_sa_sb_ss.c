#include "push_swap.h"

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
    int tmp;
    int next;

    i = 0;
    if (stc->b)
    {
        while (i < stc->qty_a)
        {
            tmp = stc->a[i + 1];
            stc->a[i + 1] = stc->a[i];

        }
    }
}