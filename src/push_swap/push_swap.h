#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#define SWAP i == 1
#define PUSH i == 2
#define ROTATE i == 3
#define REV_ROTATE i == 4

#define FIRST_A l_a->head->nb
#define SECOND_A l_a->head->next->nb
#define THIRD_A l_a->head->next->next->nb

#define FIRST_B l_b->head->nb
#define SECOND_B l_b->head->next->nb
#define THIRD_B l_b->head->next->next->nb

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

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

typedef struct  s_info
{
    char    *best_operations;
    int     best_sum;
    char    *operation;
    int     sum_oper;
    int     push_a;
    int     push_b;
    int     counter;
    int     i;
}               t_info;

/* Basic t_dlist and t_info function */

t_info      *make_info(int size);
t_dlist     *make_list(char mark);
t_dlist     *copy_list(t_dlist *l_base);
void        del_list(t_dlist **list);

/* Basic t_node function */

void    push_front_node(t_dlist *list, int n);
int     pop_front_node(t_dlist *list);
void    push_back_node(t_dlist *list, int n);
int     pop_back_node(t_dlist *list);

/* Basic movement functions */

void    swap(t_dlist *list, t_info *info);
void    push(t_dlist *list_src, t_dlist *list_dst, t_info *info);
void    rotate(t_dlist *list, t_info *info);
void    rev_rotate(t_dlist *list, t_info *info);
void    print_command(t_dlist *src, int i, t_info *info);

/* Check function */

void    q_sort(t_dlist *l_a, t_dlist *l_b, t_info *info);
void    separation_a(t_dlist *l_a, t_dlist *l_b, t_info *info);
int     separation_b(t_dlist *l_a, t_dlist *l_b, t_info *info);
void    sort_list(t_dlist *src, t_dlist *dst, t_info *info);
void    joining(t_dlist *src, t_dlist *dst, t_info *info);
int     find_median(t_dlist *src, int len);
int     check_sorted(t_dlist *src, int len);

/* find best value function */

void    try_rotate(t_dlist *l_start, t_dlist *l_a, t_dlist *l_b, t_info *info);
void    try_rev_rotate(t_dlist *l_start, t_dlist *l_a, t_dlist *l_b, t_info *info);

/* Print function */

void    put_comand(t_info *info);
void    combination(char *str, t_info *info);
void    pa_pb(char *str, int *i);
void    pb_pa(char *str, int *i);
void    ra_rra(char *str, int *i);
void    rra_ra(char *str, int *i);
void    rb_rrb(char *str, int *i);

void    put_list(t_dlist *list); // help function

#endif
