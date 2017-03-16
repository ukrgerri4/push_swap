/*
int     find_repetition(t_dlist *src, int len)
{
    t_node *tmp;

    tmp = src->head;
    while (len > 1)
    {
        if (tmp->nb != tmp->next->nb)
            return (0);
        tmp = tmp->next;
        len--;
    }
    return (1);
}


    if (FIRST > SECOND && FIRST > THIRD && SECOND > THIRD)
    {
        rotate(src);
        print_command(src, 3);
        swap(src);
        print_command(src, 1);
    }
    else if (FIRST > SECOND && FIRST > THIRD && SECOND < THIRD)
    {
        rotate(src);
        print_command(src, 3);
    }
    else if ((FIRST > SECOND && FIRST < THIRD && SECOND < THIRD) ||
            (FIRST == THIRD && FIRST > SECOND))
    {
        swap(src);
        print_command(src, 1);
    }
    else if ((FIRST < SECOND && FIRST > THIRD && SECOND > THIRD) ||
            (FIRST == SECOND && SECOND > THIRD))
    {
        rev_rotate(src);
        print_command(src, 4);
    }
    else if (FIRST < SECOND && FIRST < THIRD && SECOND > THIRD)
    {
        rev_rotate(src);
        print_command(src, 4);
        swap(src);
        print_command(src, 1);
    }

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

 void    print_command(t_dlist *src, int i)
{
    if (SWAP)
        ft_printf("s");
    else if (PUSH)
        ft_printf("p");
    else if (ROTATE)
        ft_printf("r");
    else if (REV_ROTATE)
        ft_printf("rr");
    if (src->mark == 'a' && !(PUSH))
        ft_printf("a");
    else if (src->mark == 'a' && PUSH)
        ft_printf("b");
    else if (src->mark == 'b' && !(PUSH))
        ft_printf("b");
    else if (src->mark == 'b' && PUSH)
        ft_printf("a");
    ft_printf("\n");
    sum_oper++;
}



       if (str[i] && str[i - 1] && ((str[i] == 1 && str[i - 1] == 2) || (str[i] == 2 && str[i - 1] == 1)))
        {
            str[i] = '0';
            str[i - 1] = 's';
        }
        if (str[i] && str[i - 1] &&
            ((str[i] == 5 && str[i - 1] == 6) ||
             (str[i] == 6 && str[i - 1] == 5)))
        {
            str[i] = '0';
            str[i - 1] = 'r';
        }
        if (str[i] && str[i - 1] &&
            ((str[i] == 7 && str[i - 1] == 8) ||
             (str[i] == 8 && str[i - 1] == 7)))
        {
            str[i] = '0';
            str[i - 1] = 'v';
        }

        void sort_3_elem_c(t_dlist *src)
{
    if (FIRST < SECOND && FIRST < THIRD && SECOND > THIRD)
    {
        rotate(src);
        swap(src);
        rev_rotate(src);
    }
    else if (FIRST > SECOND && FIRST < THIRD && SECOND < THIRD)
    {
        swap(src);
    }
    else if (FIRST < SECOND && FIRST > THIRD && SECOND > THIRD)
    {
        rotate(src);
        swap(src);
        rev_rotate(src);
        swap(src);
    }
    else if (FIRST > SECOND && FIRST > THIRD && SECOND > THIRD)
    {
        swap(src);
        rotate(src);
        swap(src);
        rev_rotate(src);
        swap(src);
    }
    else if (FIRST > SECOND && FIRST > THIRD && SECOND < THIRD)
    {
        swap(src);
        rotate(src);
        swap(src);
        rev_rotate(src);
    }
    else if (FIRST == SECOND && SECOND > THIRD)
    {
        rotate(src);
        swap(src);
        rev_rotate(src);
        swap(src);
    }
    else if (FIRST > SECOND && FIRST == THIRD)
    {
        swap(src);
    }
    else if (FIRST < SECOND && FIRST == THIRD)
    {
        rotate(src);
        swap(src);
        rev_rotate(src);
    }
    else if (FIRST > SECOND && SECOND == THIRD)
    {
        swap(src);
        rotate(src);
        swap(src);
        rev_rotate(src);
    }
}
*/