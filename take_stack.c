/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:07:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/27 04:06:45 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"LIBFT_42/libft.h"

static int	check_duplicates(long *tab, int y)
{
	int	i;
	int j;

	i = y;
	while (--i > 0)
	{
		j = i;
		while (tab[--j])
		{
			if (tab[i] == tab[j])
				return (0);
		}
	}
	return (1);
}

static long	*converte_to_int(char **av, int ac, long *tab)
{
	int	i;
	int	y;
	int	j;

	tab = (long *)malloc(sizeof(long) * (ac - 1));
	if (!tab)
		return (NULL);
	i = ac - 1;
	y = 0;
	while (i > 0 && y < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (free(tab), NULL);
		}
		tab[y] = ft_atoi(av[i]);
		if (tab[y] <= -2147483648 && tab[y] >= 2147483647)
			return (free(tab), NULL);
		i--;
		y++;
	}
	if (check_duplicates(tab, ac))
		return (tab);
	else
		return (free(tab), NULL);
}

t_list	*take_stack(int ac, char **av)
{
	t_list	*head = NULL;
	t_list	*tmp;
	long		*tab = NULL;
	int	i;

	tab = converte_to_int(av, ac, tab);

	// printf("|The taked int table :|\n");
	// i = -1;
	// while (++i < ac - 1)
	// 	printf("--> indix %d :=> %ld\n", i, tab[i]);
	if (!tab)
		return (NULL);
	tmp = head;
	i = -1;
	while (++i < ac - 1)
	{
		tmp = ft_lstnew(tab[i]);
		ft_lstadd_back(&head, tmp);
	}
	return (free(tab), head);
}