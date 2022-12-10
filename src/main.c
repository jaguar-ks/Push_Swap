/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/10 04:11:30 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = take_stack(ac, av);
	stack_b = NULL;
	if (!stack_a || ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ac > 2 && ac < 8)
		sort_small(&stack_a, &stack_b);
	else
		sort_by_val(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	//system("leaks push_swap");
	exit(0);
}
