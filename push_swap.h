#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_intarr {
    int *a;
    int *b;
    int qty_all;
    int qty_a;
    int qty_b;
}              t_intarr;

void    sa(t_intarr *stc);
void    sb(t_intarr *stc);
void    ss(t_intarr *stc);

#endif
