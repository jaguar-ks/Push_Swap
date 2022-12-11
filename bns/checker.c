/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:49:24 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/11 12:46:31 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/checker.h"

int	main(int ac, char **av)
{
	t_list	*sta;
	t_list	*stb;

	sta = take_stack(ac, av);
	stb = NULL;
	if (ac < 2)
		exit(0);
	if (!sta)
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
