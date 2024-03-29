/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/14 15:39:16 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = take_stack(ac, av);
	stack_b = NULL;
	if (ac <= 1)
		exit(0);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_lstsize(stack_a) >= 2 && ft_lstsize(stack_a) <= 6)
		sort_small(&stack_a, &stack_b);
	else
		sort_by_val(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	exit(0);
}
