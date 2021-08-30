/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:25:53 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/31 02:06:15 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"

static void	putcmd(char *str, int type, int n)
{
	char	c;

	if (type == -1)
		c = 'a';
	else if (type == 1)
		c = 'b';
	while (n--)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

static void	reverse(t_list **stack)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	current = *stack;
	prev = 0;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stack = prev;
	putcmd("p", 1, ft_lstsize(*stack));
}

static void	split(t_list *stack, t_list **a, t_list **b, int branch)
{
	int		half;
	t_list	*tmp;

	tmp = stack;
	half = ft_lstsize(stack) / 2;
	if (ft_lstsize(stack) % 2 == 1 && branch)
		half += 1;
	while (--half)
		tmp = tmp->next;
	if (branch == 0)
	{
		*a = tmp->next;
		tmp->next = 0;
		*b = stack;
		reverse(b);
	}
	else
	{
		*a = stack;
		*b = tmp->next;
		tmp->next = 0;
	}
}

static int	issorted(t_list *a, t_list *b)
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

static t_list	*sort(t_list *a, t_list *b, int branch)
{
	t_list	*ret;

	if (ft_lstsize(a) > 1 && ft_lstsize(b) > 1 && issorted(a, b) && branch)
	{
		ret = a;
		ft_lstadd_back(&ret, b);
		return (ret);
	}
	if (!a)
	{
		if (!branch)
		{
			branch = -1;
			putcmd("p", branch, ft_lstsize(b));
		}
		putcmd("r", branch, ft_lstsize(b));
		return (b);
	}
	else if (!b)
	{
		if (!branch)
			branch = -1;
		putcmd("r", branch, ft_lstsize(a));
		return (a);
	}
	if (!branch)
	{
		if (*((int *)a->content) < *((int *)b->content))
		{
			putcmd("r", -1, 1);
			ret = a;
			ret->next = sort(a->next, b, branch);
		}
		else
		{
			putcmd("p", -1, 1);
			putcmd("r", -1, 1);
			ret = b;
			ret->next = sort(a, b->next, branch);
		}
	}
	else
	{
		if (*((int *)a->content) < *((int *)b->content))
		{
			putcmd("r", branch, 1);
			ret = a;
			ret->next = sort(a->next, b, branch);
		}
		else
		{
			if (ft_lstsize(a) == 1 && ft_lstsize(b) == 1)
			{
				putcmd("s", branch, 1);
				putcmd("r", branch, 1);
			}
			else
			{
				putcmd("p", -branch, ft_lstsize(a));
				putcmd("r", branch, 1);
				putcmd("p", branch, ft_lstsize(a));
			}
			ret = b;
			ret->next = sort(a, b->next, branch);
		}
	}
	return (ret);
}

void	ft_mergesort(t_list **stack, int branch)
{
	int		left;
	int		right;
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	left = branch;
	right = branch;
	if (!branch)
	{
		left = -1;
		right = 1;
	}
	if (issorted(*stack, 0))
		return ;
	split(*stack, &a, &b, branch);
	if (issorted(a, 0) && !issorted(b, 0))
	{
		putcmd("r", left, ft_lstsize(a));
		ft_mergesort(&b, right);
	}
	else if (!issorted(a, 0) && issorted(b, 0))
	{
		ft_mergesort(&a, left);
		putcmd("r", right, ft_lstsize(b));
	}
	else if (!issorted(a, 0) && !issorted(b, 0))
	{
		ft_mergesort(&a, left);
		ft_mergesort(&b, right);
	}
	// ft_putstr_fd("a-----a\n", 1);
	// tmp = a;
	// while (tmp)
	// {
	// 	ft_putnbr_fd(*((int *)tmp->content), 1);
	// 	ft_putchar_fd('\n', 1);
	// 	tmp = tmp->next;
	// }
	// ft_putstr_fd("a-----a\n", 1);
	// ft_putstr_fd("b-----b\n", 1);
	// tmp = b;
	// while (tmp)
	// {
	// 	ft_putnbr_fd(*((int *)tmp->content), 1);
	// 	ft_putchar_fd('\n', 1);
	// 	tmp = tmp->next;
	// }
	// ft_putstr_fd("b-----b\n", 1);
	*stack = sort(a, b, branch);
	// if (branch == 0)
	// {
	// 	tmp = *stack;
	// 	while (tmp)
	// 	{
	// 		ft_putnbr_fd(*((int *)tmp->content), 1);
	// 		ft_putchar_fd('\n', 1);
	// 		tmp = tmp->next;
	// 	}
	// }
}
