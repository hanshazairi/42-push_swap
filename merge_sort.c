/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:25:53 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/28 17:15:52 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	split(t_list *stack, t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*tmp;

	current = stack;
	tmp = stack->next;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp)
		{
			current = current->next;
			tmp = tmp->next;
		}
	}
	*a = stack;
	*b = current->next;
	current->next = 0;
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
	if (!depth)
		reverse(&a);
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
