/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/28 18:22:10 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

static int	isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

static int	hasdup(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
			if (nums[i] == nums[j++])
				return (1);
		++i;
	}
	return (0);
}

static void	cleanup(t_list *stack, int *nums)
{
	t_list	*tmp;

	free(nums);
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

static void	error(t_list *stack, int *nums)
{
	ft_putstr_fd("Error\n", 2);
	cleanup(stack, nums);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		*nums;
	t_list	*stack;

	if (argc > 1)
	{
		len = argc - 1;
		nums = malloc(sizeof(int) * len);
		if (!nums)
			return (0);
		stack = 0;
		while (--argc)
		{
			if (!isint(argv[argc]))
				error(stack, nums);
			nums[argc - 1] = ft_atoi(argv[argc]);
			ft_lstadd_front(&stack, ft_lstnew(&nums[argc - 1]));
		}
		if (hasdup(nums, len))
			error(stack, nums);
		if (!issorted(stack))
			sort(&stack);
		cleanup(stack, nums);
	}
	return (0);
}
