/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:38:36 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/28 15:43:12 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	stack_min(t_list *stack)
{
	int		min;
	int		num;

	min = *((int *)stack->content);
	while (stack)
	{
		num = *((int *)stack->content);
		if (min > num)
			min = num;
		stack = stack->next;
	}
	return (min);
}

int	stack_max(t_list *stack)
{
	int		max;
	int		num;

	max = *((int *)stack->content);
	while (stack)
	{
		num = *((int *)stack->content);
		if (max < num)
			max = num;
		stack = stack->next;
	}
	return (max);
}

int	issorted(t_list *stack)
{
	while (stack->next)
	{
		if (*((int *)stack->content) > *((int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
