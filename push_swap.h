#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#define SA swap(l_a)
#define SB swap(l_b)
#define SS  SA;\
            SB;
#define PA push(l_b, l_a)
#define PB push(l_a, l_b)
#define RA rotate(l_a)
#define RB rotate(l_b)
#define RR  RA;\
            RB;
#define RRA rev_rotate(l_a)
#define RRB rev_rotate(l_b)
#define RRR RRA;\
            RRB;

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct  s_node
{
    int             nb;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

typedef struct s_dlist {
    t_node  *head;
    t_node  *tail;
    int     size;
}               t_dlist;

/* Basic t_dlist function */

t_dlist     *make_list(void);
void        del_list(t_dlist **list);

/* Basic t_node function */

void    push_front_node(t_dlist *list, int n);
int     pop_front_node(t_dlist *list);
void    push_back_node(t_dlist *list, int n);
int     pop_back_node(t_dlist *list);

void    put_list(t_dlist *list); // help function

/* Basic movement functions */

void    swap(t_dlist *list);
void    push(t_dlist *list_src, t_dlist *list_dst);
void    rotate(t_dlist *list);
void    rev_rotate(t_dlist *list);

/* Check function*/

void    stupid_sort(t_dlist *list);

#endif
