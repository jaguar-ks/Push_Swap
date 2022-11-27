/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/27 01:30:55 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int walo(int t)
{
	return (t+1);
}

void	print_stack(t_list *sa, t_list *sb)
{
	t_list *tmp = sa;
	t_list *tmp1 = sb;

	ft_printf("~|stack A|~\t~|stack B|~\n");
	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
	while (tmp)
	{
		printf("|%d|", tmp->content);
		if (tmp1)
		{
			printf("\t\t|%d|.\n", tmp1->content);
			tmp1 = tmp1->next;
		}
		else
			printf("\t\t|no element|.\n");
		tmp = tmp->next;
	}
	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	t_list	*tmp1;

	stack_a = take_stack(ac, av);
	stack_b = ft_lstmap(stack_a, walo);
	tmp = stack_a;
	tmp1 = stack_b;
	if (!stack_a || ac <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	print_stack(stack_a, stack_b);
	ft_printf("~~ the operations made ~~\n");
	sa(stack_a, 'a');
	pa(&stack_b, &stack_a, 'a');
	print_stack(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	system("leaks push_swap");
}