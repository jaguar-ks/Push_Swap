/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:44:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/14 15:39:49 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

// void	print_stack(t_list *sa, t_list *sb)
// {
// 	t_list	*tmp;
// 	t_list	*tmp1;

// 	tmp = sa;
// 	tmp1 = sb;
// 	ft_printf("~|stack A|~\t~|stack B|~\n");
// 	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
// 	if (!tmp && !tmp1)
// 		printf("    |the stacks have been freed|\n");
// 	while (tmp || tmp1)
// 	{
// 		if (tmp)
// 		{
// 			ft_printf("|%d|->%d(%d).", tmp->content, tmp->idx, tmp->st);
// 			tmp = tmp->next;
// 		}
// 		if (tmp1)
// 		{
// 			ft_printf("\t\t|%d|->%d(%d).", tmp1->content, tmp1->idx, tmp1->st);
// 			tmp1 = tmp1->next;
// 		}
// 		ft_printf("\n");
// 	}
// 	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
// 	ft_printf("~|size of A[%d]|~\t~|size of B[%d]|~\n",
// 		ft_lstsize(sa), ft_lstsize(sb));
// 	ft_printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
// }
