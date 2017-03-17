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

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"

int sum_oper; // DELETE

char *g_oper;

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
    int size;
    int push_a;
    int push_b;
}               t_info;
/* Basic t_dlist and t_info function */

t_info      *make_info(int size);
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
void    print_command(t_dlist *src, int i);

/* Check function */

void    q_sort(t_dlist *l_a, t_dlist *l_b, t_info *info);
void    separation_a(t_dlist *l_a, t_dlist *l_b, t_info *info);
int     separation_b(t_dlist *l_a, t_dlist *l_b, t_info *info);
void    sort_list(t_dlist *src, t_dlist *dst, t_info *info);
void    joining(t_dlist *src, t_dlist *dst, t_info *info);
int     find_median(t_dlist *src, int len);
int     check_sorted(t_dlist *src, int len);

void sort_3_elem_a(t_dlist *src, t_dlist *dst);
void sort_3_elem_b(t_dlist *src, t_dlist *dst);

/* Print function */

void    vivod(char *str);

#endif
