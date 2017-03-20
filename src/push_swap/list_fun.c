/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:44:52 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 17:45:58 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*make_list(char mark)
{
	t_dlist	*tmp;

	if (!(tmp = (t_dlist*)malloc(sizeof(t_dlist))))
		exit(1);
	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->size = 0;
	tmp->mark = mark;
	return (tmp);
}

void	del_list(t_dlist **list)
{
	t_node	*tmp;
	t_node	*next;

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

t_info	*make_info(int size)
{
	t_info *tmp;

	if (!(tmp = (t_info*)malloc(sizeof(t_info))))
		exit(1);
	tmp->best_operations = ft_strnew(100000);
	tmp->best_sum = 0;
	tmp->operation = ft_strnew(100000);
	tmp->sum_oper = 0;
	tmp->push_a = size;
	tmp->push_b = 0;
	tmp->counter = 0;
	tmp->i = 0;
	return (tmp);
}

t_dlist	*copy_list(t_dlist *l_base)
{
	t_dlist	*tmp;
	t_node	*tmp_base;
	int		i;

	i = 0;
	tmp = make_list('a');
	tmp_base = l_base->head;
	while (i++ < l_base->size)
	{
		push_back_node(tmp, tmp_base->nb);
		tmp_base = tmp_base->next;
	}
	tmp->size = l_base->size;
	return (tmp);
}
