#include "push_swap.h"

void    rrb_rb(char *str, int *i)
{
    int n;

    n = 0;
    while (str[*i] && str[*i - (2 * n + 1)] && str[*i] == '8' && str[*i - (2 * n + 1)] == '6')
    {
        str[*i] = '0';
        str[(*i)++ - (2 * n++ + 1)] = '0';
    }
}

void    sasb_rarb_rrarrb(char *str, int i)
{
    if (str[i] && str[i - 1] && ((str[i] == '1' && str[i - 1] == '2') ||
                                 (str[i] == '2' && str[i - 1] == '1')))
    {
        str[i] = '0';
        str[i - 1] = 's';
    }
    if (str[i] && str[i - 1] && ((str[i] == '5' && str[i - 1] == '6') ||
                                 (str[i] == '6' && str[i - 1] == '5')))
    {
        str[i] = '0';
        str[i - 1] = 'r';
    }
    if (str[i] && str[i - 1] && ((str[i] == '7' && str[i - 1] == '8') ||
                                 (str[i] == '8' && str[i - 1] == '7')))
    {
        str[i] = '0';
        str[i - 1] = 'v';
    }
}

void    revrite_operation(char *str, t_info *info)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (str[i])
    {
        if (str[i] != '0')
            n++;
        i++;
    }
    info->sum_oper = n;
}

void combination(char *str, t_info *info)
{
    int i;
    int n;

    i = 0;
    while (str[i])
    {
        pa_pb(str, &i);
        pb_pa(str, &i);
        ra_rra(str, &i);
        rra_ra(str, &i);
        rb_rrb(str, &i);
        rrb_rb(str, &i);
        sasb_rarb_rrarrb(str, i);
        i++;
    }
    revrite_operation(str, info);
}