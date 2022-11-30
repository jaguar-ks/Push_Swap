/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/30 07:55:29 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa(t_list *a, t_list *b, char c)
{
	t_list	*tmp;

	ft_lstadd_front(b, ft_lstnew(a->content));
	tmp = stack_dup(a->next);
	ft_lstclear(&a);
	a = tmp;
	ft_printf("p%c\n", c);
}
