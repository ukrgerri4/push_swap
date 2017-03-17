#include "push_swap.h"

void    q_sort(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
    if (info->push_a > 3 && !(check_sorted(l_a, info->push_a)))
            separation_a(l_a, l_b, info);
    if (info->push_b > 3 && !(check_sorted(l_b, info->push_b)))
    {
        if (separation_b(l_a, l_b, info))
            return ;
    }
    if (check_sorted(l_a, l_a->size) && l_b->size == 0)
        return ;
    else
    {
        sort_list(l_a, l_b, info);
        joining(l_a, l_b, info);
    }
}


int         main(int argc, char **argv)
{
    t_dlist *l_start;
    t_dlist *l_a;
    t_dlist *l_b;
    t_info  *info;
    int     i;

    if (argc > 1)
    {
        i = 0;
        l_start = make_list('a');
        l_b = make_list('b');
        while (++i < argc)
            push_back_node(l_start, ft_atoi(argv[i]));
        info = make_info(i - 1);
        l_start->size = i - 1;
        i = 0;
        while (i < 50)
        {
            l_a = copy_list(l_start);

            while (info->counter++ < i)
                rotate(l_a, info);
            q_sort(l_a, l_b, info); // (i - 1) - количество элементов в списке

            /*----------------------------------*/
            vivod(info->operation, info);
            ft_printf("-------------END------------\n");
//            put_list(l_a);
//            ft_printf("\n");
//            put_list(l_b);
//            ft_printf("-----------------------------\n");
            /*----------------------------------*/

            if ((info->sum_oper < info->best_sum) || info->best_sum == 0)
            {
                ft_bzero(info->best_operations, (size_t)info->best_sum);
                info->best_sum = info->sum_oper;
                ft_strcpy(info->best_operations, info->operation);
                ft_bzero(info->operation, (size_t)info->sum_oper);
                info->sum_oper = 0;
                info->push_a = l_start->size;
                info->push_b = 0;
                info->counter = 0;
                info->i = 0;
                del_list(&l_a);
            }
            else
            {
                ft_bzero(info->operation, (size_t)info->sum_oper);
                info->sum_oper = 0;
                info->push_a = l_start->size;
                info->push_b = 0;
                info->counter = 0;
                info->i = 0;
                del_list(&l_a);
            }
            i++;
        }
        i = 0;
        while (i < 50)
        {
            l_a = copy_list(l_start);

            while (info->counter++ < i)
                rev_rotate(l_a, info);
            q_sort(l_a, l_b, info); // (i - 1) - количество элементов в списке

            /*----------------------------------*/
            vivod(info->operation, info);
            ft_printf("-------------END------------\n");
//            put_list(l_a);
//            ft_printf("\n");
//            put_list(l_b);
//            ft_printf("-----------------------------\n");
            /*----------------------------------*/

            if ((info->sum_oper < info->best_sum) || info->best_sum == 0)
            {
                ft_bzero(info->best_operations, (size_t)info->best_sum);
                info->best_sum = info->sum_oper;
                ft_strcpy(info->best_operations, info->operation);
                ft_bzero(info->operation, (size_t)info->sum_oper);
                info->sum_oper = 0;
                info->push_a = l_start->size;
                info->push_b = 0;
                info->counter = 0;
                info->i = 0;
                del_list(&l_a);
            }
            else
            {
                ft_bzero(info->operation, (size_t)info->sum_oper);
                info->sum_oper = 0;
                info->push_a = l_start->size;
                info->push_b = 0;
                info->counter = 0;
                info->i = 0;
                del_list(&l_a);
            }
            i++;
        }
    }
    return (0);
}
