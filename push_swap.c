/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/02 14:14:31 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(void);
int		validate1(char **strs);
int		*validate2(char **strs, int len);
void	ft_mergesort(t_list **stack, int depth, int branch);

static void	cleanup(int	*nums, t_list *stack, char **strs, int len)
{
	t_list	*tmp;

	free(nums);
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	while (strs[++len])
		free(strs[len]);
	free(strs);
}

int	issorted(t_list *stack)
{
	int	min;

	min = *((int *)stack->content);
	while (stack)
	{
		if (min > *((int *)stack->content))
			return (0);
		min = *((int *)stack->content);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		*nums;
	char	**strs;
	t_list	*stack;

	if (argc != 2)
		ft_error();
	strs = ft_split(argv[1], ' ');
	len = validate1(strs);
	nums = validate2(strs, len);
	stack = 0;
	while (len--)
		ft_lstadd_front(&stack, ft_lstnew(&nums[len]));
	ft_mergesort(&stack, 0, -1);
	cleanup(nums, stack, strs, len);
	return (0);
}
