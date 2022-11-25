/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:04 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/25 01:01:13 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"./LIBFT_42/libft.h"
#include"./ft_printf/ft_printf.h"

void walo(int t)
{
	printf("\t\t~~(node %d is freed)~~\n", t);
}

int main(int ac, char **av)
{
	t_list	*stack;
	t_list	*tmp;
    int i = 0;
	stack = take_stack(ac, av);
	tmp = stack;
	if (!stack || ac <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	ft_printf("\t\t\t~|the stack taken|~\n\n");
	ft_printf("\t-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~--~-~-~-~-~-\n");
	while (tmp)
	{
		printf("\t\t=:> The node nbr :(%d) content's is= |%d|. \n", i++, tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\t-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~--~-~-~-~-~-\n");
	ft_lstclear(&stack, walo);
	//system("leaks push_swap");
}