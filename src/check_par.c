/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:16:45 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/11 16:16:42 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	check_dup_range(t_list *tab)
{
	t_list	*tmp;
	t_list	*cr;

	tmp = tab;
	cr = tmp->next;
	while (tmp)
	{
		cr = tmp->next;
		while (cr)
		{
			if ((tmp->content < INT_MIN || tmp->content > INT_MAX)
				|| (tmp->content == cr->content))
				return (0);
			cr = cr->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_arg(char *r)
{
	int	i;

	i = -1;
	if (r[0] == '-' || r[0] == '+')
		i++;
	while (r[++i])
		if (!ft_isdigit(r[i]))
			return (0);
	return (1);
}
