#include "push_swap.h"

void    pa_pb(char *str, int *i)
{
    int n;

    n = 0;
    while (str[*i] && str[*i - (2 * n + 1)] && str[*i] == '3' && str[*i - (2 * n + 1)] == '4')
    {
        str[*i] = '0';
        str[(*i)++ - (2 * n++ + 1)] = '0';
    }
}

void    pb_pa(char *str, int *i)
{
    int n;

    n = 0;
    while (str[*i] && str[*i - (2 * n + 1)] && str[*i] == '4' && str[*i - (2 * n + 1)] == '3')
    {
        str[*i] = '0';
        str[(*i)++ - (2 * n++ + 1)] = '0';
    }
}

void    ra_rra(char *str, int *i)
{
    int n;

    n = 0;
    while (str[*i] && str[*i - (2 * n + 1)] && str[*i] == '5' && str[*i - (2 * n + 1)] == '7')
    {
        str[*i] = '0';
        str[(*i)++ - (2 * n++ + 1)] = '0';
    }
}

void    rra_ra(char *str, int *i)
{
    int n;

    n = 0;
    while (str[*i] && str[*i - (2 * n + 1)] && str[*i] == '7' && str[*i - (2 * n + 1)] == '5')
    {
        str[*i] = '0';
        str[(*i)++ - (2 * n++ + 1)] = '0';
    }
}

void    rb_rrb(char *str, int *i)
{
    int n;

    n = 0;
    while (str[*i] && str[*i - (2 * n + 1)] && str[*i] == '6' && str[*i - (2 * n + 1)] == '8')
    {
        str[*i] = '0';
        str[(*i)++ - (2 * n++ + 1)] = '0';
    }
}
