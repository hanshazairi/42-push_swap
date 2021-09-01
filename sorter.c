/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:34:52 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/01 23:27:46 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		issorted(t_list *a, t_list *b);
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
void	putcmd(char *str, int branch, int n);
void	split(t_list *stack, t_list **a, t_list **b, int depth);
t_list	*reverse(t_list *stack);
t_list	*sort_132(t_list *stack, int depth, int branch);
t_list	*sort_213(t_list *stack, int depth, int branch);
t_list	*sort_231(t_list *stack, int depth, int branch);
t_list	*sort_312(t_list *stack, int depth, int branch);
t_list	*sort_321(t_list *stack, int depth, int branch);

t_list	*sort2(t_list *stack, int depth, int branch)
{
	t_list	*ret;

	(void)depth;
	putcmd("s", branch, 1);
	ret = reverse(stack);
	return (ret);
}

t_list	*sort3(t_list *stack, int depth, int branch)
{
	int		num1;
	int		num2;
	int		num3;
	t_list	*ret;

	num1 = *((int *)stack->content);
	num2 = *((int *)(stack->next)->content);
	num3 = *((int *)((stack->next)->next)->content);
	if (num1 == stack_min(stack) && num2 == stack_max(stack))
		ret = sort_132(stack, depth, branch);
	else if (num2 == stack_min(stack) && num3 == stack_max(stack))
		ret = sort_213(stack, depth, branch);
	else if (num3 == stack_min(stack) && num2 == stack_max(stack))
		ret = sort_231(stack, depth, branch);
	else if (num2 == stack_min(stack) && num1 == stack_max(stack))
		ret = sort_312(stack, depth, branch);
	else if (num3 == stack_min(stack) && num1 == stack_max(stack))
		ret = sort_321(stack, depth, branch);
	return (ret);
}

static t_list	*sort(t_list *a, t_list *b, int depth, int branch)
{
	int		tmp;
	t_list	*ret;

	if (!a)
	{
		tmp = ft_lstsize(b);
		while (tmp--)
		{
			if (depth == 1)
				// putcmd("p0-", branch, 1);
				putcmd("p", branch, 1);
			// putcmd("r0-", branch, 1);
			putcmd("r", branch, 1);
		}
		return (b);
	}
	else if (!b)
	{
		if (depth == 1)
			// putcmd("p0+", branch, ft_lstsize(b));
			putcmd("p", branch, ft_lstsize(b));
		// putcmd("r0+", branch, ft_lstsize(a));
		putcmd("r", branch, ft_lstsize(a));
		return (a);
	}
	if (*((int *)a->content) < *((int *)b->content))
	{
		// putcmd("r<", branch, 1);
		putcmd("r", branch, 1);
		ret = a;
		ret->next = sort(a->next, b, depth, branch);
	}
	else
	{
		if (depth == 1)
		{
			// putcmd("p>1", branch, 1);
			// putcmd("r>1", branch, 1);
			putcmd("p", branch, 1);
			putcmd("r", branch, 1);
			ret = b;
			ret->next = sort(a, b->next, depth, branch);
		}
		else
		{
			// putcmd("p>>", -branch, ft_lstsize(a));
			// putcmd("r>>", branch, 1);
			// putcmd("p>>", branch, ft_lstsize(a));
			putcmd("p", -branch, ft_lstsize(a));
			putcmd("r", branch, 1);
			putcmd("p", branch, ft_lstsize(a));
			ret = b;
			ret->next = sort(a, b->next, depth, branch);
		}
	}
	return (ret);
}

void	ft_mergesort(t_list **stack, int depth, int branch)
{
	int		othbranch;
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	if (issorted(*stack, 0))
		return ;
	if (ft_lstsize(*stack) == 2)
		*stack = sort2(*stack, depth, branch);
	if (ft_lstsize(*stack) == 3)
		*stack = sort3(*stack, depth, branch);
	if (ft_lstsize(*stack) == 2 || ft_lstsize(*stack) == 3)
		return ;
	split(*stack, &a, &b, depth++);
	// ft_putstr_fd("a-a-a-a\n", 1);
	// tmp = a;
	// while (tmp)
	// {
	// 	ft_putnbr_fd(*((int *)tmp->content), 1);
	// 	ft_putchar_fd('\n', 1);
	// 	tmp = tmp->next;
	// }
	// ft_putstr_fd("a-a-b-b\n", 1);
	// tmp = b;
	// while (tmp)
	// {
	// 	ft_putnbr_fd(*((int *)tmp->content), 1);
	// 	ft_putchar_fd('\n', 1);
	// 	tmp = tmp->next;
	// }
	// ft_putstr_fd("b-b-b-b\n", 1);
	othbranch = branch;
	if (depth == 1)
		othbranch = 1;
	ft_mergesort(&a, depth, branch);
	if (depth > 1)
		// putcmd("r-", branch, ft_lstsize(a));
		putcmd("r", branch, ft_lstsize(a));
	ft_mergesort(&b, depth, othbranch);
	if (depth > 1)
		// putcmd("rr+", branch, ft_lstsize(a));
		putcmd("rr", branch, ft_lstsize(a));
	*stack = sort(a, b, depth, branch);
	// putcmd("rr-+", branch, ft_lstsize(*stack));
	putcmd("rr", branch, ft_lstsize(*stack));
	// if (depth == 1)
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
