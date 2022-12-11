# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/12/11 11:05:26 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_MD = take_stack.c\
				check_par.c\
				check_sort.c\
				check_need_of_act.c\
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
				find_best_mark.c\
				send_a_to_b.c\
				send_b_to_a.c\
				to_the_top_and_align.c\
				main.c\
				#print_stack.c\#

BNS = checker.c\
		get_next_line.c\
		get_next_line_utils.c\
		swap_ch.c\
		rotate_ch.c\
		reverse_rotate_ch.c\
		push_ch.c\
		read_and_do.c\
		take_stack.c\
		check_sort.c\
		check_par.c\

FLAGS = -Wall -Wextra -Werror

CC = cc

SRC_DIR = src

SRC_MD = $(addprefix $(SRC_DIR)/,$(SRCS_MD))

OBJ_DIR = obj

OBJS_MD = $(addprefix $(OBJ_DIR)/,${SRCS_MD:.c=.o})

BNS_DIR = bns

OBJ_B_DIR = obj_b

BNS_S = $(addprefix ${BNS_DIR}/,${BNS})

OBJS_BN = ${addprefix ${OBJ_B_DIR}/,${BNS:.c=.o}}

HEADER = inc/push_swap.h

BNS_H = inc/checker.h

NAME = push_swap

BNS_NAME = checker

RM = rm -rf

all : ${OBJ_DIR} ${NAME} ${BNS_NAME}

${NAME} : ${OBJS_MD}
	make -C ./libtool
	${CC} ${FLAGS} $^ ./libtool/libft.a -o $@

${BNS_NAME} : ${OBJS_BN}
	${CC} ${FLAGS} $^ ./libtool/libft.a -o $@

${OBJ_B_DIR}/%.o : ${BNS_DIR}/%.c ${BNS_H} ${HEADER}
	@${CC} -g ${FLAGS} -c $< -o $@

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c ${HEADER}
	@${CC} -g ${FLAGS} -c $< -o $@

$(OBJ_DIR) :
	mkdir ${OBJ_DIR}
	mkdir ${OBJ_B_DIR}

clean :
	${RM} ${OBJ_DIR} ${OBJ_B_DIR} libtool/*.o

fclean : clean
	${RM} ${NAME} ${BNS_NAME} libtool/*.a

re : fclean all

.PHONY : all clean fclean re

.SILENT : ${NAME} ${BNS_NAME} clean fclean $(OBJ_DIR) re 
