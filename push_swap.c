/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/10/01 14:12:00 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		len;
	int		*nums;
	char	*str;
	char	**strs;
	t_list	*stack;

	if (argc > 1)
	{
		str = ft_join(argv + 1, " ");
		strs = ft_split(str, ' ');
		free(str);
		nums = 0;
		len = convert(strs, &nums);
		cleanup_1(strs);
		if (!len)
			error(1);
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(&nums[len]));
		if (!issorted(stack))
			sort(&stack);
		free(nums);
		cleanup_2(stack);
	}
	return (0);
}
