/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manupilation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:58:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/29 01:54:42 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*stack_to_arr(t_list *stack)
{
	int		i;
	int		*tab;
	t_list	*tmp;

	tab = (int *)malloc(sizeof(int) * ft_lstsize(stack));
	if (!tab)
		return (NULL);
	i = -1;
	tmp = stack;
	while (++i < ft_lstsize(stack))
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
	}
	return (tab);
}

void	stack_fast_sort(t_list *stack)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		mv;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next)
			tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->content > tmp1->content)
			{
				mv = tmp->content;
				tmp->content = tmp1->content;
				tmp1->content = mv;
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

t_list	*stack_dup(t_list *src)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*dst;

	tmp = src;
	dst = NULL;
	while (tmp)
	{
		new = ft_lstnew(tmp->content);
		ft_lstadd_back(&dst, new);
		tmp = tmp->next;
	}
	return (dst);
}
