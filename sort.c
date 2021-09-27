/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:34:52 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/28 00:02:35 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	sort_3(t_list **stack)
{
	const int	num_1 = *((int *)(*stack)->content);
	const int	num_2 = *((int *)(*stack)->next->content);
	const int	num_3 = *((int *)(*stack)->next->next->content);

	if (num_1 == stack_min(*stack) && num_2 == stack_max(*stack))
		sort_132(stack);
	else if (num_2 == stack_min(*stack) && num_3 == stack_max(*stack))
		sort_213(stack);
	else if (num_3 == stack_min(*stack) && num_2 == stack_max(*stack))
		sort_231(stack);
	else if (num_2 == stack_min(*stack) && num_1 == stack_max(*stack))
		sort_312(stack);
	else
		sort_321(stack);
}

static void	sort_big(t_list **stack_a)
{
	int		a;
	int		b;
	t_list	*stack_b;

	while (ft_lstsize(*stack_a) > 3)
	{
		px(stack_a, &stack_b);
		ft_putendl_fd("pb", 1);
	}
	if (!issorted(*stack_a))
		sort_3(stack_a);
	while (ft_lstsize(stack_b))
	{
		a = 0;
		b = 0;
		find_min_rotate(*stack_a, stack_b, &a, &b);
		rotate(stack_a, &stack_b, a, b);
		px(&stack_b, stack_a);
		ft_putendl_fd("pa", 1);
	}
}

static void	sort_final(t_list **stack)
{
	int	i;

	i = stack_idx_minmax(*stack, stack_min(*stack));
	if (i <= (ft_lstsize(*stack) + 1) / 2)
	{
		while (i--)
		{
			rx(stack);
			ft_putendl_fd("ra", 1);
		}
	}
	else
	{
		i = ft_lstsize(*stack) - i;
		while (i--)
		{
			rrx(stack);
			ft_putendl_fd("rra", 1);
		}
	}
}

void	sort(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
	{
		sx(stack);
		ft_putendl_fd("sa", 1);
	}
	else if (ft_lstsize(*stack) == 3)
		sort_3(stack);
	else
		sort_big(stack);
	sort_final(stack);
}
