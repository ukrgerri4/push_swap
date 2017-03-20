/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:36:49 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 17:38:18 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_last_pushed_element(t_dlist *src, int median, int len)
{
	t_node *tmp;

	tmp = src->head;
	if (src->mark == 'a')
	{
		while (len > 0)
		{
			if (tmp->nb < median)
				return (0);
			tmp = tmp->next;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			if (tmp->nb >= median)
				return (0);
			tmp = tmp->next;
			len--;
		}
	}
	return (1);
}

void	joining(t_dlist *l_a, t_dlist *l_b, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->push_b)
	{
		push(l_b, l_a, info);
		i++;
	}
}
