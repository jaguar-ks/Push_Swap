/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:07:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 00:59:40 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	check_dup_range(t_list *tab)
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
			if ((tmp->content <= -2147483648 && tmp->content >= 2147483647)
				|| (tmp->content == cr->content))
				return (0);
			cr = cr->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	check_arg(char *r)
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

// static long	*converte_to_int(char **av, int ac, long *tab)
// {
// 	int	i;
// 	int	y;
// 	int	j;

// 	tab = (long *)malloc(sizeof(long) * (ac));
// 	if (!tab)
// 		return (NULL);
// 	i = ac;
// 	y = -1;
// 	while (--i > 0 && ++y < ac)
// 	{
// 		j = -1;
// 		while (av[i][++j])
// 		{
// 			if (av[i][j] == '-' || av[i][j] == '+')
// 				j++;
// 			if (!ft_isdigit(av[i][j]))
// 				return (free(tab), NULL);
// 		}
// 		tab[y] = ft_atoi(av[i]);
// 		if (tab[y] <= -2147483648 && tab[y] >= 2147483647)
// 			return (free(tab), NULL);
// 	}
// 	if (check_duplicates(tab, ac))
// 		return (tab);
// 	else
// 		return (free(tab), NULL);
// }
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
	if (ft_lstsize(head) < 2)
		return (NULL);
	return (head);
}
