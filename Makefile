# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/12/08 09:59:07 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_MD = src/take_stack.c\
				src/checks.c\
 				src/swap.c\
				src/push.c\
				src/rotate.c\
				src/reverse_rotate.c\
				src/sort_small.c\
				src/sort.c\
				src/find_val.c\
				src/find_idx.c\
				src/find_position.c\
				src/stack_manupilation.c\
				src/mark_by_val.c\
				src/mark_by_idx.c\
				src/main.c\

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_MD = ${SRCS_MD:.c=.o}

HEADER = inc/push_swap.h

NAME = push_swap

RM = rm -f

all : ${NAME}

${NAME} : ${OBJS_MD}
	make -C ./libtool
	${CC} ${FLAGS} $^ ./libtool/libft.a -o $@

%.o : %.c ${HEADER}
	${CC} -g ${FLAGS} -c $< -o $@

clean :
	${RM} ${OBJS_MD} libtool/*.o

fclean : clean
	${RM} ${NAME} libtool/*.a

re : fclean all

.PHONY : all clean fclean re

.SILENT : ${NAME} clean fclean
