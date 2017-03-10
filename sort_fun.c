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
    while (tmp && len > 0)
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

void    sort_list(t_dlist *src, int size)
{
    int tmp;

    if ((size == 1) || (src->head->nb == src->tail->nb))
        return ;
    else if (size == 2)
    {
        if (src->mark == 'a')
            if (src->head->nb > src->tail->nb)
                swap(src);
        else
            if (src->head->nb < src->tail->nb)
                swap(src);
    }
}


int    separation(t_dlist *src, t_dlist *dst, int len)
{
    int     median;
    int     pushed;

    pushed = 0;
    median = find_median(src, len);
    while (len > 0)
    {
        if (src->head->nb <= median)
            push(src, dst); // можно передавать ф-ю как аргумент
        else
            rotate(src); // можно передавать ф-ю как аргумент
        len--;
        pushed++;
    }
    return (pushed);
}

void    joining(t_dlist *src, t_dlist *dst, int pushed)
{
    // стеденяем 2 отсортрованных куска стэка
}

void    q_sort(t_dlist *src, t_dlist *dst, int len)
{
//    int pushed;

    if (len > 2)
    {
        separation(src, dst, len);
        q_sort(src, dst, src->size);
        /*потом идет рекурсия -го стэка*/
//      q_sort(dst, src, pushed);
//      joining(src, dst, pushed);
    }
    else
        sort_list(src, len);
}

/*
t_node  *check_order(t_dlist *list)
{
    t_node  *tmp;

    tmp = list->head;
    while (tmp != list->tail)
    {
        if (tmp->nb > tmp->next->nb)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void    stupid_sort(t_dlist *list)
{
    int i = 0;
    t_node  *start;

    start = list->head;
    while ((list->head = check_order(list)))
    {
        swap(list);
        list->head = start;
        i++;
    }
    list->head = start;
    ft_printf("%d\n", i);
}
*/