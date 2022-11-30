# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/11/30 05:31:41 by faksouss         ###   ########.fr        #
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
				count_move_needed.c\
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
	${CC} ${FLAGS} -c $< -o $@

${makelib} :
	cd libtool; make ; cd ..;

clean :
	${RM} ${OBJS_MD} libtool/*.o

fclean : clean
	${RM} ${NAME} libtool/*.a

re : fclean all

.PHONY : all clean fclean re

.SILENT : ${makelib} clean fclean
