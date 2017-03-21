/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:28:11 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 17:29:49 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	s_checker(t_dlist *l_a, t_dlist *l_b)
{
	swap_checker(l_a);
	swap_checker(l_b);
}

void	r_checker(t_dlist *l_a, t_dlist *l_b)
{
	rotate_checker(l_a);
	rotate_checker(l_b);
}

void	v_checker(t_dlist *l_a, t_dlist *l_b)
{
	rev_rotate_checker(l_a);
	rev_rotate_checker(l_b);
}
