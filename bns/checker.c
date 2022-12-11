/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:49:24 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/11 09:37:12 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/checker.h"

int	main(int ac, char **av)
{
	t_list	*sta;
	t_list	*stb;

	sta = take_stack(ac, av);
	stb = NULL;
	if (!sta || ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	read_and_do(&sta, &stb);
	if (check_sort(sta, ft_lstsize(sta)) && !stb)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&sta);
}
