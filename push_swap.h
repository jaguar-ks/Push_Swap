/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:50:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/27 01:19:56 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"./LIBFT_42/libft.h"

t_list	*take_stack(int ac, char **av);
void    sa(t_list *stack, char c);
void    ss(t_list *stack_a, t_list *stack_b);
void    pa(t_list **sa, t_list **sb, char c);

#endif