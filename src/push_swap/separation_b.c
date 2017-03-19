#include "push_swap.h"

static void    assignment_sep_b(int *i, int *j, int *pushed)
{
    *i = 0;
    *j = 0;
    *pushed = 0;
}

static void    real_great_optimization_idea_b(t_dlist *l_b, t_info *info, int pushed, int j)
{
    while (((info->push_b - pushed) != l_b->size) && j-- > 0)
        rev_rotate(l_b, info);
}

static int    help_sep_b(t_dlist *l_a, t_dlist *l_b, t_info *info, int pushed)
{
    int     start_b;

    info->push_a = pushed;
    info->push_b = info->push_b - info->push_a;
    start_b = info->push_b - info->push_a;
    q_sort(l_a, l_b, info);
    if (start_b <= 6)
        return (1);
    return (0);

}

int            separation_b(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    int     median;
    int     pushed;
    int     i;
    int     j;

    assignment_sep_b(&i, &j, &pushed);
    median = find_median(l_b, info->push_b);
    while (i < info->push_b)
    {
        if (l_b->head->nb >= median)
        {
            push(l_b, l_a, info);
            pushed++;
        }
        else if (!(check_last_pushed_element(l_b, median, (info->push_b - i))))
        {
            rotate(l_b, info);
            j++;
        }
        else
            break ;
        i++;
    }
    real_great_optimization_idea_b(l_b, info, pushed, j);
    return (help_sep_b(l_a, l_b, info, pushed));
}
