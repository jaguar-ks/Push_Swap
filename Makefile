# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/11/26 23:07:00 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_MD = take_stack.c main.c operations.c

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_MD = ${SRCS_MD:.c=.o}

HEADER = push_swap.h

NAME = push_swap

RM = rm -f

makelib = LIBFT_42/libft.a

all : ${NAME}

${NAME} : ${OBJS_MD} ${makelib}
	${CC} ${FLAGS} $^ -o $@

%.o : %.c ${HEADER}
	@${CC} ${FLAGS} -c $< -o $@

${makelib} :
	cd LIBFT_42; make bonus; cd ..;

clean :
	${RM} ${OBJS_MD} LIBFT_42/*.o ft_printf/*.o

fclean : clean
	${RM} ${NAME} LIBFT_42/*.a ft_printf/*.a

re : fclean all

.PHONY : all clean fclean re

.SILENT : $(NAME) ${makeft} ${makelib} clean fclean
