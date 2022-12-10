/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/10 02:34:23 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

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
			ft_printf("|%d|->%d(%d).", tmp->content, tmp->idx, tmp->st);
			tmp = tmp->next;
		}
		if (tmp1)
		{
			ft_printf("\t\t|%d|->%d(%d).", tmp1->content, tmp1->idx, tmp1->st);
			tmp1 = tmp1->next;
		}
		ft_printf("\n");
	}
	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
	ft_printf("~|size of A[%d]|~\t~|size of B[%d]|~\n", ft_lstsize(sa), ft_lstsize(sb));
	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
}

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
	//print_stack(stack_a, stack_b);
	// if (check_sort(stack_a, ft_lstsize(stack_a)))
	// 	printf("stack is sorted\n");
	// else
	// 	printf("stack is NOT sorted\n");
	// ft_lstclear(&stack_a);
	//ft_lstclear(&stack_b);
	//print_stack(stack_a, stack_b);
	//system("leaks push_swap");
	// exit(0);
}
