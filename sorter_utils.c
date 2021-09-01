/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:38:36 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/01 18:18:35 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"

int	issorted(t_list *a, t_list *b)
{
	long	min;

	min = (long)INT_MIN - 1;
	while (a)
	{
		if (min > *((int *)a->content))
			return (0);
		min = *((int *)a->content);
		a = a->next;
	}
	while (b)
	{
		if (min > *((int *)b->content))
			return (0);
		min = *((int *)b->content);
		b = b->next;
	}
	return (1);
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

void	putcmd(char *str, int branch, int n)
{
	char	c;

	c = 'a';
	if (branch == 1)
		c = 'b';
	while (n--)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

t_list	*reverse(t_list *stack)
{
	t_list	*next;
	t_list	*prev;

	prev = 0;
	while (stack)
	{
		next = stack->next;
		stack->next = prev;
		prev = stack;
		stack = next;
	}
	return (prev);
}

void	split(t_list *stack, t_list **a, t_list **b, int depth)
{
	int		half;
	t_list	*tmp;

	tmp = stack;
	half = ft_lstsize(stack) / 2;
	if (ft_lstsize(stack) % 2 == 1 && depth > 0)
		half += 1;
	while (--half)
		tmp = tmp->next;
	if (depth == 0)
	{
		*a = tmp->next;
		tmp->next = 0; // revisit
		*b = reverse(stack);
		putcmd("p", 1, ft_lstsize(*b));
	}
	else
	{
		*a = stack;
		*b = tmp->next;
		tmp->next = 0; // revisit
	}
}
