/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/24 01:10:10 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"./LIBFT_42/libft.h"
#include"./ft_printf/ft_printf.h"

int main(int ac, char **av)
{
	t_list	*stack;
    
	if (ac <= 2)
		ft_putstr_fd("Error\n", 2);
	else
		stack = take_stack(ac, av);
}