#include "push_swap.h"

void    swap(t_dlist *list)
{
    int tmp;

    if (list->size >= 2)
    {
        tmp = list->head->nb;
        list->head->nb = list->head->next->nb;
        list->head->next->nb = tmp;
    }
}

void    push(t_dlist *list_src, t_dlist *list_dst)
{
    int tmp;

    if (list_src->size)
    {
        tmp = list_src->head->nb;
        push_front_node(list_dst, tmp);
        pop_front_node(list_src);
    }
}

void    rotate(t_dlist *list)
{
    int tmp;

    if (list->size == 2)
        swap(list);
    else if (list->size > 2)
    {
        tmp = list->head->nb;
        pop_front_node(list);
        push_back_node(list, tmp);
    }
}

void    rev_rotate(t_dlist *list)
{
    int tmp;

    if (list->size == 2)
        swap(list);
    else if (list->size > 2)
    {
        tmp = list->tail->nb;
        pop_back_node(list);
        push_front_node(list, tmp);
    }
}

void    print_command(t_dlist *src, int i)
{
    static int  j;


    if (SWAP && src->mark == 'a')
        g_oper[j++] = '1';
    else if (SWAP && src->mark != 'a')
        g_oper[j++] = '2';
    else if (PUSH && src->mark != 'a')
        g_oper[j++] = '3';
    else if (PUSH && src->mark == 'a')
        g_oper[j++] = '4';
    else if (ROTATE && src->mark == 'a')
        g_oper[j++] = '5';
    else if (ROTATE && src->mark != 'a')
        g_oper[j++] = '6';
    else if (REV_ROTATE && src->mark == 'a')
        g_oper[j++] = '7';
    else if (REV_ROTATE && src->mark != 'a')
        g_oper[j++] = '8';
    g_oper[j] = '\0';
    sum_oper++;
}