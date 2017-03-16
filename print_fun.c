#include "push_swap.h"

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

void vivod(char *str)
{

    int i;
    int n;

    i = 0;
    while (str[i])
    {
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '3' && str[i - (2 * n + 1)] == '4')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '4' && str[i - (2 * n + 1)] == '3')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '8' && str[i - (2 * n + 1)] == '6')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '6' && str[i - (2 * n + 1)] == '8')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '7' && str[i - (2 * n + 1)] == '5')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        n = 0;
        while (str[i] && str[i - (2 * n + 1)] && str[i] == '5' && str[i - (2 * n + 1)] == '7')
        {
            str[i] = '0';
            str[i++ - (2 * n++ + 1)] = '0';
        }
        if (str[i] && str[i - 1] &&
            ((str[i] == 1 && str[i - 1] == 2) ||
             (str[i] == 2 && str[i - 1] == 1)))
        {
            str[i] = '0';
            str[i - 1] = 'v';
        }

        i++;
    }

    i = 0;
    n = 0;
    while (str[i])
    {
        if (str[i] != '0')
        {
            ft_printf("%c", str[i]);
            n++;
        }
        i++;
    }
    ft_printf("\n");
    ft_printf("N = %d\n", n);
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