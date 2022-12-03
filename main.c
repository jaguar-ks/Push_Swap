/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 21:30:32 by faksouss         ###   ########.fr       */
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
			ft_printf("|%d|->%d.", tmp->content, tmp->idx);
			tmp = tmp->next;
		}
		if (tmp1)
		{
			ft_printf("\t\t|%d|->%d.", tmp1->content, tmp1->idx);
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
	t_list	*tmp;
	t_list	*tmp1;
	int		*tab;

	stack_a = take_stack(ac, av);
	stack_b = NULL;
	tmp = stack_a;
	tmp1 = stack_b;
	if (!stack_a || ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	// print_stack(stack_a, stack_b);
	// print_stack(stack_a, stack_b);
	// ft_printf("~>|:the size of the stack taken is := [%d]|\n", ft_lstsize(stack_a));
	// ft_printf("\t|~> the MIN_VAL =:>[%d]\n", min_val(stack_a));
	// ft_printf("\t|~> the MIN_PS =:>[%d]\n", find_pst_of_elm(stack_a, min_val(stack_a)));
	// ft_printf("\t|~> the MID_VAL =:>[%d]\n", mid_val(stack_a));
	// ft_printf("\t|~> the MID_PS =:>[%d]\n", find_pst_of_elm(stack_a, mid_val(stack_a)));
	// ft_printf("\t|~> the MAX_VAL =:>[%d]\n", max_val(stack_a));
	// ft_printf("\t|~> the MAX_PS =:>[%d]\n", find_pst_of_elm(stack_a, max_val(stack_a)));
	// ft_printf("\t|~> the psition of first small elm =:>[%d]\n", find_f_s(stack_a, mid_val(stack_a)));
	// ft_printf("\t|~> the psition of first small elm =:>[%d]\n", find_l_s(stack_a, mid_val(stack_a)));
	// ft_printf("\t|~> the RA action needed =:>[%d]\n", how_many_r(find_f_s(stack_a, mid_val(stack_a))));
	// ft_printf("\t|~> the RRA action needed =:>[%d]\n", how_many_rr(stack_a, find_l_s(stack_a, mid_val(stack_a))));
	// ft_printf("~~ the operations made ~~\n");
	// pa(&stack_a, &stack_b, 'a');
	// pa(&stack_a, &stack_b, 'a');
	// pa(&stack_a, &stack_b, 'a');
	// print_stack(stack_a, stack_b);
	// send_small(&stack_a, &stack_b, mid_val(stack_a));
	tab = stack_to_arr(stack_a);
	fast_sort(tab, stack_a);
	get_idx(&stack_a, tab);
	// print_stack(stack_a, stack_b);
	sort_more(&stack_a, &stack_b);
	// print_stack(stack_a, stack_b);
	// // ft_printf("~~ Sorting with the FORBIDEN method: ~~\n");
	// // stack_fast_sort(stack_a);
	// print_stack(stack_a, stack_b);
	if (check_sort(stack_a, ft_lstsize(stack_a)))
		printf("stack is sorted\n");
	else
		printf("stack is NOT sorted\n");
	// ft_lstclear(&stack_a);
	//ft_lstclear(&stack_b);
	//print_stack(stack_a, stack_b);
	//system("leaks push_swap");
	// exit(0);
}
