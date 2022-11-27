/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:34:23 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/27 05:12:07 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    sa(t_list *stack, char c)
{
    int  tmp;

    if (stack && stack->next)
    {
        tmp = stack->content;
        stack->content = stack->next->content;
        stack->next->content = tmp;
    }
    if (c == 'a' || c == 'b')
        ft_printf("s%c\n", c);
    else
        return ;
}

void    ss(t_list *stack_a, t_list *stack_b)
{
    sa(stack_a, 's');
    sa(stack_b, 's');
    ft_printf("ss\n");
}

void    pa(t_list **sa, t_list **sb, char c)
{
    //t_list  *tmp;

    if (sa && sb)
    {
        if (*sa)
        {
            ft_lstadd_front(sb, ft_lstnew((*sa)->content));
            if (*sa)
                *sa = (*sa)->next;
            ft_printf("p%c\n", c);
        }
    }
    return ;
}

void ra(t_list **stack, char c)
{
    if (stack)
    {
        if (*stack)
        {
            ft_lstadd_back(stack, ft_lstnew((*stack)->content));
            if ((*stack)->next)
                (*stack) = (*stack)->next;
            if (c == 'a' || c == 'b')
                ft_printf("r%c\n", c);
        }
    }
    return ;
}

void    rr(t_list **sa, t_list **sb)
{
    ra(sa, 's');
    ra(sb, 's');
    ft_printf("rr\n");
}
