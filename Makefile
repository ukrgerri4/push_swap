NAME_1 = bin/push_swap
NAME_2 = bin/checker
BIN = bin
WWW = -Wall -Wextra -Werror
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
            src/checker/move_fun.o

OBJECTS_C_PS = src/push_swap/list_fun.o \
                src/push_swap/node_fun.o \
                src/push_swap/print_fun.o \
                src/push_swap/validator.o \
                src/push_swap/find_median.o

all: $(NAME_1) $(NAME_2)

bin_dirs:
	mkdir -p $(BIN)

libft_mc:
	make -C $(LIB_PATH)

ft_printf_mc:
	make -C $(FT_PRINTF_PATH)

push_swap_obj: $(OBJECTS_PS)

checker_obj: $(OBJECTS_C) $(OBJECTS_C_PS)

$(NAME_1):  bin_dirs libft_mc ft_printf_mc push_swap_obj
	gcc $(WWW) -o $(NAME_1) $(OBJECTS_PS) $(LIBFT) $(FT_PRINTF)

$(NAME_2): bin_dirs checker_obj
	gcc $(WWW) -o $(NAME_2) $(OBJECTS_C) $(OBJECTS_C_PS) $(LIBFT) $(FT_PRINTF)

src/checker/%.o: src/checker/%.c
	gcc  $(WWW) -o $@ -c $<

src/push-swap/%.o: src/push-swap/%.c
	gcc  $(WWW) -o $@ -c $<

clean:
	make -C $(LIB_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS_PS)
	rm -f $(OBJECTS_C)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -Rf $(BIN)

re: fclean all
