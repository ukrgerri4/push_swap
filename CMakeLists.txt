cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c push_swap.h node_fun.c list_fun.c fun_move_elem.c sort_fun.c separate_join_sort.c sort_3_elem.c print_fun.c bubble_sort.c)
add_executable(push_swap ${SOURCE_FILES} main.c)
file(GLOB SOURCES_LIB ft_printf/libft/*.c)
file(GLOB SOURCES_PRINTF ft_printf/*.c)
add_library(ft STATIC ${SOURCES_LIB} ${SOURCES_PRINTF})

target_link_libraries(push_swap ft)