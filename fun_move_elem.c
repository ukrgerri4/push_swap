#include "push_swap.h"

void    swap(t_dlist *list, t_info *info)
{
    int tmp;

    if (list->size >= 2)
    {
        tmp = list->head->nb;
        list->head->nb = list->head->next->nb;
        list->head->next->nb = tmp;
        print_command(list, 1, info);
    }
}

void    push(t_dlist *list_src, t_dlist *list_dst, t_info *info)
{
    int tmp;

    if (list_src->size)
    {
        tmp = list_src->head->nb;
        push_front_node(list_dst, tmp);
        pop_front_node(list_src);
        print_command(list_src, 2, info);
    }
}

void    rotate(t_dlist *list, t_info *info)
{
    int tmp;

    if (list->size == 2)
       swap(list, info);
    else if (list->size > 2)
    {
        tmp = list->head->nb;
        pop_front_node(list);
        push_back_node(list, tmp);
        print_command(list, 3, info);
    }
}

void    rev_rotate(t_dlist *list, t_info *info)
{
    int tmp;

    if (list->size == 2)
        swap(list, info);
    else if (list->size > 2)
    {
        tmp = list->tail->nb;
        pop_back_node(list);
        push_front_node(list, tmp);
        print_command(list, 4, info);
    }
}