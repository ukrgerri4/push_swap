#include "push_swap.h"

void  push_front_node(t_dlist *list, int n)
{
    t_node  *tmp;

    if (!(tmp = (t_node*)malloc(sizeof(t_node))))
        exit (2);
    tmp->nb = n;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head)
        list->head->prev = tmp;
    list->head = tmp;
    if (list->tail == NULL)
        list->tail = tmp;
    list->size++;
}

int    pop_front_node(t_dlist *list)
{
    t_node  *prev;
    int     tmp;

    if (list->head == NULL)
        exit (3);
    prev = list->head;
    list->head = list->head->next;
    if (list->head)
        list->head->prev = NULL;
    if (prev == list->tail)
        list->tail = NULL;
    tmp = prev->nb;
    free(prev);
    list->size--;
    return (tmp);
}

void  push_back_node(t_dlist *list, int n)
{
    t_node  *tmp;

    if (!(tmp = (t_node*)malloc(sizeof(t_node))))
        exit (4);
    tmp->nb = n;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail)
        list->tail->next = tmp;
    list->tail = tmp;
    if (list->head == NULL)
        list->head = tmp;
    list->size++;
}

int    pop_back_node(t_dlist *list)
{
    t_node  *next;
    int     tmp;

    if (list->tail == NULL)
        exit (5);
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail)
        list->tail->next = NULL;
    if (next == list->head)
        list->head = NULL;
    tmp = next->nb;
    free(next);
    list->size--;
    return (tmp);
}

void    put_list(t_dlist *list)
{
    int     i;
    t_node  *tmp;

    i = 0;
    tmp = list->head;
    while (tmp)
    {
        ft_printf("%d, ", tmp->nb);
        tmp = tmp->next;
    }
    ft_printf("\nSize = %d, Mark = %c\n", list->size, list->mark);
}