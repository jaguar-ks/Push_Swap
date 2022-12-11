/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/11 10:05:08 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	pa_ch(t_list **sa, t_list **sb)
{
	t_list	*tmp;

	tmp = *sa;
	ft_lstadd_front(sb, ft_lstnew((*sa)->content, (*sa)->idx));
	*sa = (*sa)->next;
	ft_lstdelone(tmp);
}
