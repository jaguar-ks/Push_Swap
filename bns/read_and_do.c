/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:22:15 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/11 16:16:59 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/checker.h"

void	exec_opr(char *act, t_list **sta, t_list **stb)
{
	if (!ft_strncmp(act, "sa\n", 3))
		sa_ch(*sta);
	else if (!ft_strncmp(act, "sb\n", 3))
		sa_ch(*stb);
	else if (!ft_strncmp(act, "ss\n", 3))
		ss_ch(*sta, *stb);
	else if (!ft_strncmp(act, "ra\n", 3))
		ra_ch(sta);
	else if (!ft_strncmp(act, "rb\n", 3))
		ra_ch(stb);
	else if (!ft_strncmp(act, "rr\n", 3))
		rr_ch (sta, stb);
	else if (!ft_strncmp(act, "rra\n", 4))
		rra_ch(sta);
	else if (!ft_strncmp(act, "rrb\n", 4))
		rra_ch(stb);
	else if (!ft_strncmp(act, "rrr\n", 4))
		rrr_ch(sta, stb);
	else if (!ft_strncmp(act, "pa\n", 3))
		pa_ch(stb, sta);
	else if (!ft_strncmp(act, "pb\n", 3))
		pa_ch(sta, stb);
	else
		return (ft_putstr_fd("Error\n", 2), exit(1));
}

void	read_and_do(t_list **sta, t_list **stb)
{
	char	*act;

	act = get_next_line(0);
	while (act)
	{
		exec_opr(act, sta, stb);
		free(act);
		act = get_next_line(0);
	}
}
