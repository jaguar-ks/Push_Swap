/* ************************************************************************** */
/*  */
/*  :::	 ::::::::   */
/*   operations.c	  :+:   :+:	:+:   */
/*  +:+ +:+	+:+	*/
/*   By: faksouss <faksouss@student.42.fr>	+#+  +:+	   +#+  */
/*  +#+#+#+#+#+   +#+	*/
/*   Created: 2022/11/26 22:34:23 by faksouss	 #+#  #+#	*/
/*   Updated: 2022/11/27 20:18:09 by faksouss	###   ########.fr	*/
/*  */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list *stack, char c)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	else
		return ;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a, 's');
	sa(stack_b, 's');
	ft_printf("ss\n");
}

void	pa(t_list **sa, t_list **sb, char c)
{
	t_list	*tmp;

	tmp = NULL;
	if (sa && sb)
	{
		if (*sa)
		{
			ft_lstadd_front(sb, ft_lstnew((*sa)->content));
			if ((*sa)->next)
				tmp = (*sa)->next;
			ft_lstdelone(*sa);
			*sa = tmp;
			ft_printf("p%c\n", c);
		}
	}
	return ;
}

void	ra(t_list **stack, char c)
{
	t_list	*tmp;

	tmp = NULL;
	if (stack)
	{
		if (*stack)
		{
			ft_lstadd_back(stack, ft_lstnew((*stack)->content));
			if ((*stack)->next)
				tmp = (*stack)->next;
			ft_lstdelone(*stack);
			*stack = tmp;
			if (c == 'a' || c == 'b')
				ft_printf("r%c\n", c);
		}
	}
	return ;
}

void	rr(t_list **sa, t_list **sb)
{
	ra(sa, 's');
	ra(sb, 's');
	ft_printf("rr\n");
}

void	rra(t_list **stack, char c)
{
	int	i;

	i = -1;
	if (stack)
	{
		while (++i < ft_lstsize((*stack)) - 1)
			ra(stack, 'r');
		if (c == 'a' || c == 'b')
			ft_printf("rr%c\n", c);
	}
	return ;
}

void	rrr(t_list **sa, t_list **sb)
{
	rra(sa, 'd');
	rra(sb, 'd');
	ft_printf("rrr\n");
}
