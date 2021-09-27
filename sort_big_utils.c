/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:28:39 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/28 00:17:08 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	stack_idx_mid(t_list *stack, int num)
{
	int		ret;
	int		lower;
	int		upper;
	t_list	*tmp;

	ret = 1;
	tmp = stack;
	while (tmp->next)
	{
		lower = *((int *)tmp->content);
		upper = *((int *)tmp->next->content);
		if (num > lower && num < upper)
			break;
		++ret;
		tmp = tmp->next;
	}
	if (ret == ft_lstsize(stack))
		ret = 0;
	return (ret);
}

int	stack_idx_minmax(t_list *stack, int num)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = stack_max(stack);
	if (num <= stack_min(stack))
		tmp = stack_min(stack);
	else
		++ret;
	while (stack)
	{
		if (*((int *)stack->content) == tmp)
			break;
		++ret;
		stack = stack->next;
	}
	return (ret);
}

static int ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
	const int	size_a = ft_lstsize(stack_a);
	const int	size_b = ft_lstsize(stack_b);
	int		i;
	int		j;
	int		min_r;
	int		num;
	int		x;

	x = -1;
	min_r = -1;
	while (stack_b)
	{
		num = *((int *)stack_b->content);
		if (num < stack_min(stack_a) || num > stack_max(stack_a))
			i = stack_idx_minmax(stack_a, num);
		else
			i = stack_idx_mid(stack_a, num);
		++x;
		j = x;
		if (i >= (size_a + 1) / 2)
			i = -1 * (size_a - i);
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (min_r < 0 || min_r > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
			min_r = ft_abs(i) + ft_abs(j);
		}
		stack_b = stack_b->next;
	}
}

void rotate(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int i;
	int j;
	int	tmp;

	i = ft_lstsize(*stack_a);
	j = ft_lstsize(*stack_b);

	if (a >= 0 && b >= 0)
	{
		if (a <= b)
		{
			tmp = b - a;
			while (a--)
			{
				rx(stack_a);
				rx(stack_b);
				ft_putendl_fd("rr", 1);
			}
			while (tmp--)
			{
				rx(stack_b);
				ft_putendl_fd("rb", 1);
			}
		}
		else
		{
			tmp = a - b;
			while (b--)
			{
				rx(stack_a);
				rx(stack_b);
				ft_putendl_fd("rr", 1);
			}
			while (tmp--)
			{
				rx(stack_a);
				ft_putendl_fd("ra", 1);
			}
		}
	}
	else if (a < 0 && b < 0)
	{
		if (ft_abs(a) <= ft_abs(b))
		{
			tmp = ft_abs(a);
			while (tmp--)
			{
				rrx(stack_a);
				rrx(stack_b);
				ft_putendl_fd("rrr", 1);
			}
			tmp = ft_abs(b) - ft_abs(a);
			while (tmp--)
			{
				rrx(stack_b);
				ft_putendl_fd("rrb", 1);
			}
		}
		else
		{
			tmp = ft_abs(b);
			while (tmp--)
			{
				rrx(stack_a);
				rrx(stack_b);
				ft_putendl_fd("rrr", 1);
			}
			tmp = ft_abs(a) - ft_abs(b);
			while (tmp--)
			{
				rrx(stack_a);
				ft_putendl_fd("rra", 1);
			}
		}
	}
	else if (a >= 0 && b < 0)
	{
		while (a--)
		{
			rx(stack_a);
			ft_putendl_fd("ra", 1);
		}
		tmp = ft_abs(b);
		while (tmp--)
		{
			rrx(stack_b);
			ft_putendl_fd("rrb", 1);
		}
	}
	else
	{
		while (b--)
		{
			rx(stack_b);
			ft_putendl_fd("rb", 1);
		}
		tmp = ft_abs(a);
		while (tmp--)
		{
			rrx(stack_a);
			ft_putendl_fd("rra", 1);
		}
	}
}
