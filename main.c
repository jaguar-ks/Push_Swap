/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/26 23:54:08 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void walo(int t)
{
	printf("\t\t~~(node %d is freed)~~\n", t);
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	//t_list	*stack_b = NULL;
	t_list	*tmp;
    int i = 0;
	stack_a = take_stack(ac, av);
	tmp = stack_a;
	if (!stack_a || ac <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	sa(stack_a, 'a');
	ft_printf("\t\t\t~|the stack taken|~\n\n");
	ft_printf("\t-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~--~-~-~-~-~-\n");
	while (tmp)
	{
		printf("\t\t=:> The node nbr :(%d) content's is= |%d|. \n", i++, tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\t-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~--~-~-~-~-~-\n");
	ft_lstclear(&stack_a, walo);
	//system("leaks push_swap");
}