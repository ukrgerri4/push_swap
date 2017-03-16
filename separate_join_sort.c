#include "push_swap.h"

int     find_median(t_dlist *src, int len)
{
    t_node  *tmp;
    int max;
    int min;
    int median;

    tmp = src->head;
    max = tmp->nb;
    min = tmp->nb;
    while (len > 0)
    {
        if (tmp->nb > max)
            max = tmp->nb;
        if (tmp->nb < min)
            min = tmp->nb;
        tmp = tmp->next;
        len--;
    }
    median = (min + max) / 2;
    return (median);
}

int     check_last_pushed_element(t_dlist *src, int median,int len)
{
    t_node *tmp;

    tmp = src->head;
    if (src->mark == 'a')
    {
        while (len > 0) {
            if (tmp->nb <= median)
                return (0);
            tmp = tmp->next;
            len--;
        }
    }
    else
    {
        while (len > 0) {
            if (tmp->nb >= median)
                return (0);
            tmp = tmp->next;
            len--;
        }
    }
    return (1);
}

int    separation_a(t_dlist *src, t_dlist *dst, int len)
{
    int     median;
    int     pushed;
    int     tmp_len;
    int     i;

    pushed = 0;
    tmp_len = len;
    median = find_median(src, len);
    while (len > 0)
    {
        if (src->head->nb <= median)
        {
            push(src, dst);
            pushed++;
        }
        else if (!(check_last_pushed_element(src, median, len)))
            rotate(src);
        else
            break ;
        len--;
    }
    i = 0;
    while (((tmp_len - len - pushed) != src->size) &&
            (i++ < (tmp_len - len - pushed)))
        rev_rotate(src);
    return (pushed);
}

int    separation_b(t_dlist *src, t_dlist *dst, int len)
{
    int     median;
    int     pushed;
    int     tmp_len;
    int     i;

    pushed = 0;
    tmp_len = len;
    median = find_median(src, len);
    while (len > 0) {
        if (src->head->nb >= median)
        {
            push(src, dst);
            pushed++;
        }
        else if (!(check_last_pushed_element(src, median, len)))
            rotate(src);
        else
            break ;
        len--;
    }
    i = 0;
    while (i++ < (tmp_len - len - pushed))
        rev_rotate(src);
    return (pushed);
}

void    joining(t_dlist *src, t_dlist *dst, int pushed)
{
    while (pushed > 0)
    {
        push(src, dst);
        pushed--;
    }
}

void    sort_list(t_dlist *src, t_dlist *dst, int len)
{
    if (len == 2)
    {
        if (src->mark == 'a')
        {
            if (src->head->nb > src->head->next->nb)
            {
                swap(src);
//                if (dst->head->nb < dst->head->next->nb)
//                    swap(dst);
            }
        }
        else
        {
            if (src->head->nb < src->head->next->nb)
            {
                swap(src);
//                if (dst->head->nb > dst->head->next->nb)
//                    swap(dst);

            }
        }
    }

    else if (len == 3)
    {
        if (src->mark == 'a')
            sort_3_elem_a(src, dst);
        else
            sort_3_elem_b(src, dst);
    }

}