NAME = push_swap
WWW = -Wall -Wextra -Werror
LIB_PATH = src/libft/
LIBFT = $(LIB_PATH)libft.a
FT_PRINTF_PATH = src/ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

OBJECTS = src/push_swap/find_best_value.o src/push_swap/list_fun.o \
            src/push_swap/print_fun.o src/push_swap/sort.o \
            src/push_swap/find_median.o src/push_swap/main.o \
            src/push_swap/fun_move_elem.o src/push_swap/node_fun.o \
            src/push_swap/separate_join.o

all: $(NAME)

libft_mc:
	make -C $(LIB_PATH)

ft_printf_mc:
	make -C $(FT_PRINTF_PATH)

push_swap_obj: $(OBJECTS)

$(NAME): libft_mc ft_printf_mc push_swap_obj
	gcc $(WWW) -o $(NAME) $(OBJECTS) $(LIBFT) $(FT_PRINTF)

src/push-swap/%.o: src/push-swap/%.c
	gcc  $(WWW) -o $@ -c $<

clean:
	make -C $(LIB_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -f $(NAME)

re: fclean all
