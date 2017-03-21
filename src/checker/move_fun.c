/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:27:14 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 17:27:45 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_checker(t_dlist *list)
{
	int tmp;

	if (list->size >= 2)
	{
		tmp = list->head->nb;
		list->head->nb = list->head->next->nb;
		list->head->next->nb = tmp;
	}
}

void	push_checker(t_dlist *list_src, t_dlist *list_dst)
{
	int tmp;

	if (list_src->size)
	{
		tmp = list_src->head->nb;
		push_front_node(list_dst, tmp);
		pop_front_node(list_src);
	}
}

void	rotate_checker(t_dlist *list)
{
	int tmp;

	if (list->size == 2)
		swap_checker(list);
	else if (list->size > 2)
	{
		tmp = list->head->nb;
		pop_front_node(list);
		push_back_node(list, tmp);
	}
}

void	rev_rotate_checker(t_dlist *list)
{
	int tmp;

	if (list->size == 2)
		swap_checker(list);
	else if (list->size > 2)
	{
		tmp = list->tail->nb;
		pop_back_node(list);
		push_front_node(list, tmp);
	}
}
