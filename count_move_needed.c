/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move_needed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:31:15 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/30 10:18:53 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	how_many_r(int ps)
{
	int		mv;

	mv = 0;
	while (ps >= 0)
	{
		mv++;
		ps--;
	}
	return (mv);
}

int	how_many_rr(t_list *stack, int ps)
{
	int		mv;

	mv = 0;
	while (ps < ft_lstsize(stack))
	{
		mv++;
		ps++;
	}
	return (mv);
}