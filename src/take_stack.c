/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:07:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/14 15:14:35 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_list	*take_stack(int ac, char **av)
{
	t_list	*head;
	int		i;
	int		j;
	char	**r;

	head = NULL;
	i = 0;
	while (++i < ac)
	{
		j = -1;
		r = ft_split(av[i], ' ');
		while (r[++j])
		{
			if (check_arg(r[j]))
				ft_lstadd_back(&head, ft_lstnew(ft_atoi(r[j]), 0));
			else
				return (ft_lstclear(&head), deallocate(r));
		}
		if (!check_dup_range(head))
			return (ft_lstclear(&head), deallocate(r), NULL);
		deallocate(r);
	}
	if (!ft_lstsize(head))
		return (NULL);
	return (head);
}
