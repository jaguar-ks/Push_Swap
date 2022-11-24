/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:07:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/24 18:04:34 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"./LIBFT_42/libft.h"
#include"./ft_printf/ft_printf.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cr;

	if (lst)
	{
		if (*lst)
		{
			cr = ft_lstlast(*lst);
			cr->next = new;
		}
		else
			*lst = new;
	}
}

static int	check_duplicates(long *tab)
{
	int	i;
	int j;

	i = 0;
	while (tab[i++])
	{
		j = i + 1;
		while (tab[j++])
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

	tab = (long *)malloc(sizeof(long) * (ac - 1));
	if (!tab)
		return (NULL);
	i = 1;
	y = 0;
	while (i < ac && y < ac)
	{
		tab[y] = ft_atoi(av[i]);
		if (tab[y] <= -2147483648 && tab[y] >= 2147483647)
			return (NULL);
		i++;
		y++;
	}
	return (tab);
}

t_list	*take_stack(int ac, char **av)
{
	t_list	*head;
	t_list	*tmp;
	long		*tab = NULL;
	int	i;

	tab = converte_to_int(av, ac, tab);
	// printf("|The taked int table :\n|");
	// i = -1;
	// while (++i < ac - 1)
	// 	printf("--> indix %d :=> %ld\n", i, tab[i]);
	if (!tab)
		return (NULL);
	if (!check_duplicates(tab))
		return (NULL);
	tmp = head;
	i = -1;
	while (++i < ac - 1)
	{
		tmp = ft_lstnew(tab[i]);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}