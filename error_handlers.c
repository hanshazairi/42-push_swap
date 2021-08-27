/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:26:03 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/27 16:07:14 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

static int	isvalid(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

static int	isdistinct(int *nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
			if (nums[i] == nums[j++])
				return (0);
		++i;
	}
	return (1);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	validate1(char **strs)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (strs[len])
	{
		str = strs[len++];
		if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX || !isvalid(str))
		{
			i = 0;
			while (strs[i])
				free(strs[i++]);
			free(strs);
			ft_error();
		}
	}
	return (len);
}

int	*validate2(char **strs, int len)
{
	int	i;
	int	*nums;

	nums = malloc(len * sizeof(int));
	if (!nums)
	{
		i = 0;
		while (strs[i])
			free(strs[i++]);
		free(strs);
		ft_error();
	}
	i = -1;
	while (++i < len)
		nums[i] = ft_atol(strs[i]);
	if (!isdistinct(nums))
	{
		free(nums);
		i = 0;
		while (strs[i])
			free(strs[i++]);
		free(strs);
		ft_error();
	}
	return (nums);
}
