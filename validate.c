/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:34:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/10/01 17:04:54 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

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

int	convert(char **strs, int **nums)
{
	int	i;
	int	ret;
	int	*tmp;

	i = 0;
	while (strs[i])
		if (!ft_isint(strs[i++]))
			return (0);
	ret = i;
	tmp = malloc(sizeof(int) * i);
	if (!tmp)
		return (0);
	while (i--)
		tmp[i] = ft_atoi(strs[i]);
	if (hasdup(tmp, ret))
	{
		free(tmp);
		ret = 0;
	}
	*nums = tmp;
	return (ret);
}

void	check(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		if (!ft_strlen(argv[i++]))
			ft_error(1);
}

void	cleanup_1(char *str, char **strs)
{
	int	i;

	i = 0;
	free(str);
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	cleanup_2(int *nums, t_list *stack)
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
