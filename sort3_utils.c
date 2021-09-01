/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:05:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/02 00:51:08 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	putcmd(char *str, int branch, int n);
void	split(t_list *stack, t_list **a, t_list **b, int depth);
t_list	*reverse(t_list *stack);

t_list	*sort_132(t_list *stack, int depth, int branch)
{
	t_list	*a;
	t_list	*b;
	t_list	*ret;

	if (depth < 2)
	{
		putcmd("s", branch, 1);
		putcmd("r", branch, 1);
	}
	else
	{
		putcmd("r", branch, 1);
		putcmd("s", branch, 1);
		putcmd("rr", branch, 1);
	}
	split(stack, &a, &b, ++depth);
	ret = a;
	b->next = a->next;
	ret->next = b;
	return (ret);
}

t_list	*sort_213(t_list *stack, int depth, int branch)
{
	t_list	*a;
	t_list	*b;
	t_list	*ret;

	putcmd("s", branch, 1);
	split(stack, &a, &b, ++depth);
	ret = reverse(a);
	ft_lstadd_back(&ret, b);
	return (ret);
}

t_list	*sort_231(t_list *stack, int depth, int branch)
{
	t_list	*a;
	t_list	*b;
	t_list	*ret;

	if (depth < 2)
		putcmd("rr", branch, 1);
	else
	{
		putcmd("r", branch, 1);
		putcmd("r", branch, 1);
		putcmd("p", -branch, 1);
		putcmd("rr", branch, 1);
		putcmd("rr", branch, 1);
		putcmd("p", branch, 1);
	}
	split(stack, &a, &b, ++depth);
	ret = a;
	ft_lstadd_front(&ret, b);
	return (ret);
}

t_list	*sort_312(t_list *stack, int depth, int branch)
{
	t_list	*a;
	t_list	*b;
	t_list	*ret;

	if (depth < 2)
		putcmd("r", branch, 1);
	else
	{
		putcmd("p", -branch, 1);
		putcmd("r", branch, 1);
		putcmd("r", branch, 1);
		putcmd("p", branch, 1);
		putcmd("rr", branch, 1);
		putcmd("rr", branch, 1);
	}
	split(stack, &a, &b, ++depth);
	ret = reverse(a);
	b->next = ret->next;
	ret->next = b;
	return (ret);
}

t_list	*sort_321(t_list *stack, int depth, int branch)
{
	t_list	*a;
	t_list	*b;
	t_list	*ret;

	if (depth < 2)
	{
		putcmd("s", branch, 1);
		putcmd("rr", branch, 1);
	}
	else
	{
		putcmd("s", branch, 1);
		putcmd("r", branch, 1);
		putcmd("r", branch, 1);
		putcmd("p", -branch, 1);
		putcmd("rr", branch, 1);
		putcmd("rr", branch, 1);
		putcmd("p", branch, 1);
	}
	split(stack, &a, &b, ++depth);
	ret = reverse(a);
	ft_lstadd_front(&ret, b);
	return (ret);
}
