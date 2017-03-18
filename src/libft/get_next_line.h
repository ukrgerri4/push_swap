/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:42:54 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/01/16 18:46:43 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 32

typedef struct		s_buf
{
	char			*buf;
	int				fd;
	struct s_buf	*next;
}					t_buf;

int					get_next_line(const int fd, char **line);
#endif
