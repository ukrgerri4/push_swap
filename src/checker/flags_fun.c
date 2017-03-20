/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:20:54 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/03/20 17:26:52 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_flag	*make_flags(void)
{
	t_flag	*tmp;

	tmp = (t_flag*)malloc(sizeof(t_flag));
	tmp->v_flag = 0;
	return (tmp);
}

char	**check_flags(int *argc, char **argv, t_flag *flag)
{
	char	**tmp_argv;

	tmp_argv = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		argv++;
		(*argc)--;
		flag->v_flag = 1;
	}
	return (argv);
}
