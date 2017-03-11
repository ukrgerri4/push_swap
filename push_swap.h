#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#define SWAP i == 1
#define PUSH i == 2
#define ROTATE i == 3
#define REV_ROTATE i == 4

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"

int sum_oper; // DELETE

typedef struct  s_node
{
    int             nb;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

typedef struct s_dlist {
    t_node  *head;
    t_node  *tail;
    int     size; // возможно нужно удалить
    char    mark;
}               t_dlist;

/* Basic t_dlist function */

t_dlist     *make_list(char mark);
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

int     find_median(t_dlist *src, int len);
void    sort_list(t_dlist *src, int len);
int     separation_a(t_dlist *src, t_dlist *dst, int len);
int     separation_b(t_dlist *src, t_dlist *dst, int len);
int     find_repetition(t_dlist *src, int len);
void    joining(t_dlist *src, t_dlist *dst, int pushed);
int     check_sorted(t_dlist *src, int len);
void    print_command(t_dlist *src, int i);
void    q_sort(t_dlist *src, t_dlist *dst, int len);

#endif
