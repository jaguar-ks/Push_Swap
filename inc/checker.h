/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:40:18 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/11 11:01:08 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include"push_swap.h"
# include"get_next_line.h"

void	read_and_do(t_list **sta, t_list **stb);
void	sa_ch(t_list *stack);
void	ss_ch(t_list *stack_a, t_list *stack_b);
void	ra_ch(t_list **stack);
void	rr_ch(t_list **sa, t_list **sb);
void	pa_ch(t_list **sa, t_list **sb);
void	rra_ch(t_list **stack);
void	rrr_ch(t_list **sa, t_list **sb);

#endif
