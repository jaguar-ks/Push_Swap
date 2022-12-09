# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/12/09 01:20:51 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_MD = take_stack.c\
				checks_par.c\
				checks_sort.c\
				checks_need_of_act.c\
 				swap.c\
				push.c\
				rotate.c\
				reverse_rotate.c\
				sort_small.c\
				sort.c\
				find_val.c\
				find_idx.c\
				find_position.c\
				stack_manupilation.c\
				mark_by_val.c\
				mark_by_idx.c\
				find_best_mark.c\
				main.c\

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_MD = $(addprefix $(OBJ_DIR)/,${SRCS_MD:.c=.o})
SRC_MD = $(addprefix $(SRC_DIR)/,$(SRCS_MD))

SRC_DIR = src

OBJ_DIR = obj

HEADER = inc/push_swap.h

NAME = push_swap

RM = rm -rf

all : ${OBJ_DIR} ${NAME}

${NAME} : ${OBJS_MD}
	@make -C ./libtool
	@${CC} ${FLAGS} $^ ./libtool/libft.a -o $@

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c ${HEADER}
	@${CC} -g ${FLAGS} -c $< -o $@

$(OBJ_DIR) :
	mkdir ${OBJ_DIR}

clean :
	${RM} ${OBJ_DIR} libtool/*.o

fclean : clean
	${RM} ${NAME} libtool/*.a

re : fclean all

.PHONY : all clean fclean re

.SILENT : ${NAME} clean fclean $(OBJ_DIR) re 
