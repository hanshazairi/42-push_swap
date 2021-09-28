/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:28:39 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/28 17:08:39 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	stack_idx_mid(t_list *stack, int num)
{
	const int	size = ft_lstsize(stack);
	int			ret;
	int			current;
	int			next;

	ret = 1;
	while (stack->next)
	{
		current = *((int *)stack->content);
		next = *((int *)stack->next->content);
		if (num > current && num < next)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret == size)
		ret = 0;
	else if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	stack_idx_minmax(t_list *stack, int num)
{
	const int	size = ft_lstsize(stack);
	int			ret;
	int			x;

	ret = 0;
	x = stack_max(stack);
	if (num <= stack_min(stack))
		x = stack_min(stack);
	else
		++ret;
	while (stack)
	{
		if (*((int *)stack->content) == x)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
	const int	size_b = ft_lstsize(stack_b);
	int			i;
	int			j;
	int			num;
	int			x;

	x = -1;
	while (stack_b && ++x >= 0)
	{
		num = *((int *)stack_b->content);
		if (num < stack_min(stack_a) || num > stack_max(stack_a))
			i = stack_idx_minmax(stack_a, num);
		else
			i = stack_idx_mid(stack_a, num);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*a) + ft_abs(*b) > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
		}
		stack_b = stack_b->next;
	}
}

void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		run("rr", stack_a, stack_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			run("rb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			run("ra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
	else
	{
		run("rrr", stack_a, stack_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			run("rrb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			run("rra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
}

void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		run("ra", stack_a, 0, a);
		run("rrb", stack_b, 0, ft_abs(min(a, b)));
	}
	else
	{
		run("rb", stack_b, 0, b);
		run("rra", stack_a, 0, ft_abs(min(a, b)));
	}
}
