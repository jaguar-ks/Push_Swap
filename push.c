/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/30 08:50:37 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa(t_list **sa, t_list **sb, char c)
{
	t_list	*tmp;

	tmp = *sa;
	ft_lstadd_front(sb, ft_lstnew(tmp->content));
	*sa = (*sa)->next;
	// ft_lstdelone(tmp);
	// ft_lstclear(&a);
	// a = tmp;
	ft_printf("p%c\n", c);
}
