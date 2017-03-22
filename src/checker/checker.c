/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:12:11 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 18:57:59 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		escape(void)
{
	ft_printf("Error\n");
	return (1);
}

int		use_operation(t_dlist *l_a, t_dlist *l_b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap_checker(l_a);
	else if (!ft_strcmp(line, "sb"))
		swap_checker(l_b);
	else if (!ft_strcmp(line, "pa"))
		push_checker(l_b, l_a);
	else if (!ft_strcmp(line, "pb"))
		push_checker(l_a, l_b);
	else if (!ft_strcmp(line, "ra"))
		rotate_checker(l_a);
	else if (!ft_strcmp(line, "rb"))
		rotate_checker(l_b);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate_checker(l_a);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate_checker(l_b);
	else if (!ft_strcmp(line, "ss"))
		s_checker(l_a, l_b);
	else if (!ft_strcmp(line, "rr"))
		r_checker(l_a, l_b);
	else if (!ft_strcmp(line, "rrr"))
		v_checker(l_a, l_b);
	else
		return (escape());
	return (0);
}

void	check_result(t_dlist *l_a)
{
	int		i;
	t_node	*tmp;

	i = 1;
	tmp = l_a->head;
	while (i < l_a->size)
	{
		if (tmp->nb > tmp->next->nb)
		{
			ft_printf("\x1b[31mKO\x1b[0m\n");
			return ;
		}
		tmp = tmp->next;
		i++;
	}
	ft_printf("\x1b[32mOK\x1b[0m\n");
}

int		checker(int argc, char **argv, int flag)
{
	t_dlist *l_a;
	t_dlist *l_b;
	char	*line;
	int		i;

	i = 0;
	line = 0;
	l_a = make_list('a');
	l_b = make_list('b');
	while (++i < argc)
		push_back_node(l_a, ft_atoi(argv[i]));
	while (get_next_line(0, &line))
	{
		if (use_operation(l_a, l_b, line) == 1)
			return (0);
		if (flag)
			put_list(l_a);
	}
	check_result(l_a);
	ft_strdel(&line);
	del_list(&l_a);
	del_list(&l_b);
	return (0);
}

int		main(int argc, char **argv)
{
    int flag;

	flag = 0;
	if (argc > 1)
	{
		argv = check_flags(&argc, argv, &flag);
		if (validation(argc, argv))
		{
			ft_printf("Error\n");
			return (0);
		}
		checker(argc, argv, flag);
	}
	return (0);
}
