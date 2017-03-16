#include "push_swap.h"

t_dlist    *make_list(char mark)
{
    t_dlist *tmp;

    if (!(tmp = (t_dlist*)malloc(sizeof(t_dlist))))
        exit (1);
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->size = 0;
    tmp->mark = mark;
    return (tmp);
}

void    del_list(t_dlist **list)
{
    t_node  *tmp;
    t_node  *next;

    tmp = (*list)->head;
    next = NULL;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    *list = NULL;
}