cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/push_swap/main.c src/push_swap/push_swap.h src/push_swap/node_fun.c src/push_swap/list_fun.c src/push_swap/fun_move_elem.c src/push_swap/sort.c src/push_swap/check_join.c src/push_swap/find_best_value.c src/push_swap/print_fun.c src/push_swap/find_median.c src/push_swap/combination_0.c src/push_swap/combination_1.c src/push_swap/separation_a.c src/push_swap/separation_b.c src/push_swap/validator.c src/checker/flags_fun.c)
add_executable(push_swap ${SOURCE_FILES} src/push_swap/main.c)
file(GLOB SOURCES_LIB src/libft/*.c)
file(GLOB SOURCES_PRINTF src/ft_printf/*.c)
add_library(ft STATIC ${SOURCES_LIB} ${SOURCES_PRINTF})

target_link_libraries(push_swap ft)