/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:53:25 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/29 22:36:13 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sx(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack_1) >= 2)
	{
		tmp = (*stack_1)->next;
		(*stack_1)->next = tmp->next;
		ft_lstadd_front(stack_1, tmp);
	}
}

void	px(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_1))
	{
		tmp = *stack_1;
		*stack_1 = (*stack_1)->next;
		ft_lstadd_front(stack_2, tmp);
	}
}

void	rx(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack_1) >= 2)
	{
		tmp = *stack_1;
		*stack_1 = (*stack_1)->next;
		tmp->next = 0;
		ft_lstadd_back(stack_1, tmp);
	}
}

void	rrx(t_list **stack_1, t_list **stack_2)
{
	t_list	*last;
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack_1) >= 2)
	{
		last = *stack_1;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack_1;
		*stack_1 = last;
	}
}

void	run(char *str, t_list **stack_1, t_list **stack_2, int x)
{
	const int	len = ft_strlen(str);
	int			tmp;
	void		(*f)(t_list **, t_list **);

	tmp = ft_abs(x);
	if (!ft_strncmp(str, "sa", len) || !ft_strncmp(str, "sb", len)
		|| !ft_strncmp(str, "ss", len))
		f = &sx;
	else if (!ft_strncmp(str, "pa", len) || !ft_strncmp(str, "pb", len))
		f = &px;
	else if (!ft_strncmp(str, "ra", len) || !ft_strncmp(str, "rb", len)
		|| !ft_strncmp(str, "rr", len))
		f = &rx;
	else
		f = &rrx;
	while (tmp--)
	{
		f(stack_1, stack_2);
		if (stack_2 && f != px)
			f(stack_2, 0);
		if (x > 0)
			ft_putendl_fd(str, 1);
	}
}
