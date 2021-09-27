/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:53:25 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/26 20:31:49 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sx(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) >= 2)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		ft_lstadd_front(stack, tmp);
	}
}

void	px(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a))
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, tmp);
	}
}

void	rx(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) >= 2)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = 0;
		ft_lstadd_back(stack, tmp);
	}
}

void	rrx(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*stack) >= 2)
	{
		last = *stack;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack;
		*stack = last;
	}
}
