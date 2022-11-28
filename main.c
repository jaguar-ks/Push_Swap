/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 04:45:03 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	walo(int t)
{
	return (t * 10);
}

void	print_stack(t_list *sa, t_list *sb)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = sa;
	tmp1 = sb;
	ft_printf("~|stack A|~\t~|stack B|~\n");
	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
	if (!tmp && !tmp1)
		printf("    |the stacks have been freed|\n");
	while (tmp || tmp1)
	{
		if (tmp)
		{
			ft_printf("|%d|.", tmp->content);
			tmp = tmp->next;
		}
		if (tmp1)
		{
			ft_printf("\t\t|%d|.", tmp1->content);
			tmp1 = tmp1->next;
		}
		ft_printf("\n");
	}
	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	t_list	*tmp1;

	stack_a = take_stack(ac, av);
	stack_b = NULL;
	tmp = stack_a;
	tmp1 = stack_b;
	if (!stack_a || ac <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	// print_stack(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	ft_printf("~~ the operations made ~~\n");
	sort_stack(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	// ss(stack_a, stack_b);
	// print_stack(stack_a, stack_b);
	// pa(&stack_a, &stack_b, 'a');
	// pa(&stack_a, &stack_b, 'a');
	// pa(&stack_a, &stack_b, 'a');
	// print_stack(stack_a, stack_b);
	// ra(&stack_b, 'b');
	// print_stack(stack_a, stack_b);
	// rra(&stack_b, 'b');
	// print_stack(stack_a, stack_b);
	// rr(&stack_a, &stack_b);
	// print_stack(stack_a, stack_b);
	// pa(&stack_b, &stack_a, 'b');
	// pa(&stack_b, &stack_a, 'b');
	// pa(&stack_b, &stack_a, 'b');
	// print_stack(stack_a, stack_b);
	// rrr(&stack_a, &stack_b);
	// print_stack(stack_a, stack_b);
	// ft_lstclear(&stack_a);
	if (check_sort(stack_a))
		printf("stack is sorted\n");
	else
		printf("stack is NOT sorted\n");
	ft_lstclear(&stack_a);
	print_stack(stack_a, stack_b);
	system("leaks push_swap");
}
