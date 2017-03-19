#include "push_swap.h"

void    print_command(t_dlist *src, int i, t_info *info)
{
    if (SWAP && src->mark == 'a')
        info->operation[info->i++] = '1';
    else if (SWAP && src->mark != 'a')
        info->operation[info->i++] = '2';
    else if (PUSH && src->mark != 'a')
        info->operation[info->i++] = '3';
    else if (PUSH && src->mark == 'a')
        info->operation[info->i++] = '4';
    else if (ROTATE && src->mark == 'a')
        info->operation[info->i++] = '5';
    else if (ROTATE && src->mark != 'a')
        info->operation[info->i++] = '6';
    else if (REV_ROTATE && src->mark == 'a')
        info->operation[info->i++] = '7';
    else if (REV_ROTATE && src->mark != 'a')
        info->operation[info->i++] = '8';
    info->operation[info->i] = '\0';
    info->sum_oper++;
}

void    put_list(t_dlist *list)
{
    int     i;
    t_node  *tmp;

    i = 1;
    tmp = list->head;
    while (tmp)
    {
        ft_printf("%d, ", tmp->nb);
        tmp = tmp->next;
    }
    tmp = list->head;
    while (i < list->size)
    {
        if (tmp->nb > tmp->next->nb)
        {
            ft_printf("\nKO\n");
            break ;
        }
        tmp = tmp->next;
        i++;
    }
    ft_printf("\nSize = %d, Mark = %c\n", list->size, list->mark);
}

void put_comand(t_info *info)
{
    while (info->best_operations[++(info->i)])
    {
        if (info->best_operations[info->i] == '1')
            ft_printf("sa\n");
        else if (info->best_operations[info->i] == '2')
            ft_printf("sb\n");
        else if (info->best_operations[info->i] == '3')
            ft_printf("pa\n");
        else if (info->best_operations[info->i] == '4')
            ft_printf("pb\n");
        else if (info->best_operations[info->i] == '5')
            ft_printf("ra\n");
        else if (info->best_operations[info->i] == '6')
            ft_printf("rb\n");
        else if (info->best_operations[info->i] == '7')
            ft_printf("rra\n");
        else if (info->best_operations[info->i] == '8')
            ft_printf("rrb\n");
        else if (info->best_operations[info->i] == 's')
            ft_printf("ss\n");
        else if (info->best_operations[info->i] == 'r')
            ft_printf("rr\n");
        else if (info->best_operations[info->i] == 'v')
            ft_printf("rrr\n");
    }
}