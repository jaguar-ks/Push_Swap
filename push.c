/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 00:37:17 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
