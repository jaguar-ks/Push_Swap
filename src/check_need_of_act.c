/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:42 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/09 01:18:42 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	check_to_push(t_list *st)
{
	t_list *tmp;

	tmp = st;
	while (tmp)
	{
		if (!tmp->st)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
