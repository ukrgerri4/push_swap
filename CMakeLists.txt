cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c push_swap.h fun_sa_sb_ss.c)
add_executable(push_swap ${SOURCE_FILES} main.c)
file(GLOB SOURCES_LIB libft/*.c)
file(GLOB SOURCES_PRINTF ft_printf/*.c)
add_library(ft STATIC ${SOURCES_LIB} ${SOURCES_PRINTF})

target_link_libraries(push_swap ft)