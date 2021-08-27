/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:25:53 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/28 00:41:35 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	split(t_list *head, t_list **a, t_list **b)
{
	t_list	*half;
	t_list	*tmp;

	half = head;
	tmp = head->next;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp)
		{
			half = half->next;
			tmp = tmp->next;
		}
	}
	*a = head;
	*b = half->next;
	half->next = 0;
}

static t_list	*sort(t_list *a, t_list *b)
{
	t_list	*ret;

	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (*((int *)a->content) <= *((int *)b->content))
	{
		ret = a;
		ret->next = sort(a->next, b);
	}
	else
	{
		ret = b;
		ret->next = sort(a, b->next);
	}
	return (ret);
}

void	ft_mergesort(t_list **stack, int depth)
{
	t_list	*a;
	t_list	*b;
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	ft_mergesort(&a, ++depth);
	ft_mergesort(&b, ++depth);
	*stack = sort(a, b);
	if (depth == 2)
	{
		tmp = *stack;
		while (tmp)
		{
			ft_putnbr_fd(*((int *)tmp->content), 1);
			ft_putchar_fd('\n', 1);
			tmp = tmp->next;
		}
	}
}
