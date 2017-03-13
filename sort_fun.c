#include "push_swap.h"

static void sort_only_three_elem_a(t_dlist *src)
{
    if (check_sorted(src, 3))
        return ;
    if (FIRST > SECOND && SECOND >= THIRD)
    {
        swap(src);
        print_command(src, 1);
    }
    if (SECOND > THIRD)
    {
        rev_rotate(src);
        print_command(src, 4);
    }
    if (check_sorted(src, 3))
        return ;
    if (FIRST > THIRD)
    {
        rotate(src);
        print_command(src, 3);
    }
    else
    {
        swap(src);
        print_command(src, 1);
    }
}

static void sort_only_three_elem_b(t_dlist *src)
{
    if (check_sorted(src, 3))
        return ;
    if (FIRST < SECOND && SECOND <= THIRD)
    {
        swap(src);
        print_command(src, 1);
    }
    if (SECOND < THIRD)
    {
        rev_rotate(src);
        print_command(src, 4);
    }
    if (check_sorted(src, 3))
        return ;
    if (FIRST < THIRD)
    {
        rotate(src);
        print_command(src, 3);
    }
    else
    {
        swap(src);
        print_command(src, 1);
    }
}

int     check_sorted(t_dlist *src, int len)
{
    t_node *tmp;

    tmp = src->head;
    while (len > 1)
    {
        if (src->mark == 'a')
        {
            if (tmp->nb > tmp->next->nb)
                return (0);
        }
        else
        {
            if (tmp->nb < tmp->next->nb)
                return (0);
        }
        tmp = tmp->next;
        len--;
    }
    return (1);
}

static void sort_two_elem(t_dlist *src)
{
    if (src->mark == 'a')
    {
        if (src->head->nb > src->head->next->nb)
        {
            swap(src);
            print_command(src, 1);
        }
    }
    else
    {
        if (src->head->nb < src->head->next->nb)
        {
            swap(src);
            print_command(src, 1);
        }
    }
}

static void sort_three_elem_a(t_dlist *src, t_dlist *dst)
{
    if (check_sorted(src, 3))
        return ;
    if (src->size == 3)
        sort_only_three_elem_a(src);
    else if (FIRST <= SECOND && FIRST <= THIRD)
    {
        push(src, dst);
        print_command(src, 2);
        sort_two_elem(src);
        push(dst, src);
        print_command(src, 2);
    }

}

static void sort_three_elem_b(t_dlist *src, t_dlist *dst)
{
    if (check_sorted(src, 3))
        return ;
    if (src->size == 3)
        sort_only_three_elem_b(src);
    else if (FIRST >= SECOND && FIRST >= THIRD)
    {
        push(src, dst);
        print_command(src, 2);
        sort_two_elem(src);
        push(dst, src);
        print_command(src, 2);
    }

}

void    sort_list(t_dlist *src, t_dlist *dst, int len)
{
    if (len == 2)
        sort_two_elem(src);
    if (len == 3)
    {
        if (src->mark == 'a')
            sort_three_elem_a(src, dst);
        else
            sort_three_elem_b(src, dst);
    }
}