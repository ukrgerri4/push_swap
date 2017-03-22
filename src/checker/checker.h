/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:31:20 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 17:32:23 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "../push_swap/push_swap.h"

char			**check_flags(int *argc, char **argv, int *flag);

void			swap_checker(t_dlist *list);
void			push_checker(t_dlist *list_src, t_dlist *list_dst);
void			rotate_checker(t_dlist *list);
void			rev_rotate_checker(t_dlist *list);
void			s_checker(t_dlist *l_a, t_dlist *l_b);
void			r_checker(t_dlist *l_a, t_dlist *l_b);
void			v_checker(t_dlist *l_a, t_dlist *l_b);

#endif
