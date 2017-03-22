# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 18:37:08 by ikryvenk          #+#    #+#              #
#    Updated: 2017/03/20 18:37:11 by ikryvenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = bin/push_swap
NAME_2 = bin/checker
WWW = -Wall -Wextra -Werror -pipe
LIB_PATH = src/libft/
LIBFT = $(LIB_PATH)libft.a
FT_PRINTF_PATH = src/ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

OBJECTS_PS = src/push_swap/find_best_value.o src/push_swap/list_fun.o \
            src/push_swap/print_fun.o src/push_swap/sort.o \
            src/push_swap/find_median.o src/push_swap/main.o \
            src/push_swap/fun_move_elem.o src/push_swap/node_fun.o \
            src/push_swap/check_join.o src/push_swap/separation_a.o \
            src/push_swap/separation_b.o src/push_swap/combination_0.o \
            src/push_swap/combination_1.o src/push_swap/validator.o

OBJECTS_C = src/checker/checker.o \
            src/checker/move_fun.o \
			src/checker/move_fun_1.o \
            src/checker/flags_fun.o

OBJECTS_C_PS = src/push_swap/list_fun.o \
                src/push_swap/node_fun.o \
                src/push_swap/print_fun.o \
                src/push_swap/validator.o \
                src/push_swap/find_median.o

all: $(NAME_1)

libmk:
	make -C $(LIB_PATH)

ft_printfmk:
	make -C $(FT_PRINTF_PATH)

$(NAME_1): libmk ft_printfmk $(OBJECTS_PS) $(OBJECTS_C)
	gcc $(WWW) -o $(NAME_1) $(OBJECTS_PS) $(LIBFT) $(FT_PRINTF)
	gcc $(WWW) -o $(NAME_2) $(OBJECTS_C) $(OBJECTS_C_PS) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	gcc  $(WWW) -o $@ -c $<

clean:
	make -C $(LIB_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS_PS)
	rm -f $(OBJECTS_C)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -f $(NAME_1) $(NAME_2)

re: fclean all
