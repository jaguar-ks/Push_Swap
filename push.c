/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 05:48:57 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa(t_list **sa, t_list **sb, char c)
{
	t_list	*tmp;

	tmp = *sa;
	ft_lstadd_front(sb, ft_lstnew((*sa)->content, (*sa)->idx));
	*sa = (*sa)->next;
	ft_lstdelone(tmp);
	ft_printf("p%c\n", c);
}
