#include "push_swap.h"

static void    assignment_sep_a(int *i, int *j, int *pushed)
{
    *i = 0;
    *j = 0;
    *pushed = 0;
}

static void    real_great_optimization_idea_a(t_dlist *l_a, t_info *info, int pushed, int j)
{
    while (((info->push_a - pushed) != l_a->size) && j-- > 0)
        rev_rotate(l_a, info);
}

static void    help_sep_a(t_dlist *l_a, t_dlist *l_b, t_info *info, int pushed)
{
    int     start_b;

    start_b = info->push_b;
    info->push_b = pushed;
    info->push_a = info->push_a - info->push_b;
    q_sort(l_a, l_b, info);
    info->push_b = start_b;
}

void            separation_a(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int     median;
    int     pushed;
    int     i;
    int     j;

    assignment_sep_a(&i, &j, &pushed);
    median = find_median(l_a, info->push_a);
    while (i < info->push_a)
    {
        if (l_a->head->nb < median)
        {
            push(l_a, l_b, info);
            pushed++;
        }
        else if (!(check_last_pushed_element(l_a, median, (info->push_a - i))))
        {
            rotate(l_a, info);
            j++;
        }
        else
            break ;
        i++;
    }
    real_great_optimization_idea_a(l_a, info, pushed, j);
    help_sep_a(l_a, l_b, info, pushed);
}
