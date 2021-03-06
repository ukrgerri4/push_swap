/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:58:07 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 18:00:06 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_elem_a(t_dlist *l_a, t_info *info)
{
	if (FIRST_A < SECOND_A && FIRST_A < THIRD_A && SECOND_A > THIRD_A)
	{
		rev_rotate(l_a, info);
		swap(l_a, info);
	}
	else if (FIRST_A > SECOND_A && FIRST_A < THIRD_A && SECOND_A < THIRD_A)
		swap(l_a, info);
	else if (FIRST_A < SECOND_A && FIRST_A > THIRD_A && SECOND_A > THIRD_A)
		rev_rotate(l_a, info);
	else if (FIRST_A > SECOND_A && FIRST_A > THIRD_A && SECOND_A > THIRD_A)
	{
		swap(l_a, info);
		rev_rotate(l_a, info);
	}
	else if (FIRST_A > SECOND_A && FIRST_A > THIRD_A && SECOND_A < THIRD_A)
		rotate(l_a, info);
}

static void	sort_3_elem_b(t_dlist *l_b, t_info *info)
{
	if (FIRST_B < SECOND_B && FIRST_B < THIRD_B && SECOND_B > THIRD_B)
		rotate(l_b, info);
	else if (FIRST_B > SECOND_B && FIRST_B < THIRD_B && SECOND_B < THIRD_B)
		rev_rotate(l_b, info);
	else if (FIRST_B < SECOND_B && FIRST_B > THIRD_B && SECOND_B > THIRD_B)
		swap(l_b, info);
	else if (FIRST_B < SECOND_B && FIRST_B < THIRD_B && SECOND_B < THIRD_B)
	{
		swap(l_b, info);
		rev_rotate(l_b, info);
	}
	else if (FIRST_B > SECOND_B && FIRST_B > THIRD_B && SECOND_B < THIRD_B)
	{
		rev_rotate(l_b, info);
		swap(l_b, info);
	}
}

int			check_sorted(t_dlist *src, int len)
{
	t_node	*tmp;
	int		tmp_len;

	tmp = src->head;
	tmp_len = len;
	while (tmp_len > 1)
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
		tmp_len--;
	}
	return (1);
}

void		sort_list(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
	int	flag_a;
	int	flag_b;

	flag_a = 0;
	flag_b = 0;
	(l_a->size == 3) ? sort_3_elem_a(l_a, info) : 0;
	(l_b->size == 3) ? sort_3_elem_b(l_b, info) : 0;
	(l_a->head && FIRST_A > SECOND_A) ? swap(l_a, info) : 0;
	(l_b->head && FIRST_B < SECOND_B) ? swap(l_b, info) : 0;
	if (!(check_sorted(l_a, info->push_a)))
	{
		rotate(l_a, info);
		flag_a = 1;
	}
	if (!(check_sorted(l_b, info->push_b)))
	{
		rotate(l_b, info);
		flag_b = 1;
	}
	(l_a->head && FIRST_A > SECOND_A) ? swap(l_a, info) : 0;
	(l_b->head && FIRST_B < SECOND_B) ? swap(l_b, info) : 0;
	(flag_a != 0) ? rev_rotate(l_a, info) : 0;
	(flag_b != 0) ? rev_rotate(l_b, info) : 0;
	(l_a->head && FIRST_A > SECOND_A) ? swap(l_a, info) : 0;
	(l_b->head && FIRST_B < SECOND_B) ? swap(l_b, info) : 0;
}
