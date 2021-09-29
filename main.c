/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/29 14:34:59 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

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
