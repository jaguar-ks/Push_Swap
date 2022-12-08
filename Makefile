# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/12/08 05:35:18 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_MD = take_stack.c\
 				swap.c\
				push.c\
				rotate.c\
				reverse_rotate.c\
				sort_stack.c\
				find_min_max.c\
				stack_manupilation.c\
				main.c\

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_MD = ${SRCS_MD:.c=.o}

HEADER = push_swap.h

NAME = push_swap

RM = rm -f

makelib = libtool/libft.a

all : ${NAME}

${NAME} : ${OBJS_MD} ${makelib}
	${CC} ${FLAGS} $^ -o $@

%.o : %.c ${HEADER}
	${CC} -g ${FLAGS} -c $< -o $@

${makelib} :
	cd libtool; make ; cd ..;

clean :
	${RM} ${OBJS_MD} libtool/*.o

fclean : clean
	${RM} ${NAME} libtool/*.a

re : fclean all

.PHONY : all clean fclean re

.SILENT : ${makelib} clean fclean
