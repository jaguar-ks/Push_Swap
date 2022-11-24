/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/24 18:04:06 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"./LIBFT_42/libft.h"
#include"./ft_printf/ft_printf.h"

int main(int ac, char **av)
{
	t_list	*stack;
    
	stack = take_stack(ac, av);
	if (!stack || ac <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}