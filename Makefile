# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 19:48:40 by deman_wolf        #+#    #+#              #
#    Updated: 2022/11/26 15:24:14 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_MD = take_stack.c push_swap.c

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_MD = ${SRCS_MD:.c=.o}

HEADER = push_swap.h

NAME = push

RM = rm -f

makelib = LIBFT_42/libft.a

makeft = ft_printf/libftprintf.a

all : ${NAME}

${NAME} : ${OBJS_MD} ${makelib} ${makeft} where
	@${CC} ${FLAGS} $<  ${makelib} ${makeft} -o $@

where : 
	@pwd

%.o : %.c ${HEADER}
	@${CC} ${FLAGS} -c $< -o $@

${makelib} :
	@cd LIBFT_42; make bonus; cd ..;

${makeft} :
	@cd ft_printf; make; cd ..;

clean :
	@${RM} ${OBJS_MD} LIBFT_42/*.o ft_printf/*.o

fclean : clean
	@${RM} ${NAME} LIBFT_42/*.a ft_printf/*.a

re : fclean all

.PHONY : all clean fclean re
