/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:50:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 05:28:14 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"LIBFT_42/libft.h"

t_list	*take_stack(int ac, char **av);
void    sa(t_list *stack, char c);
void    ss(t_list *stack_a, t_list *stack_b);
void    pa(t_list **src, t_list **dst, char c);
void    ra(t_list *stack, char c);
void    rr(t_list *sa, t_list *sb);
void    rra(t_list *stack, char c);
void    rrr(t_list *sa, t_list *sb);
void    sort_stack(t_list *stack_a, t_list *stack_b);
int     check_sort(t_list *stack);

#endif