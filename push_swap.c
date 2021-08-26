/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/26 22:00:14 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

static void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

static int	ft_isvalid(int c)
{
	return (ft_isdigit(c) || c == ' ' || c == '-');
}

int	main(int argc, char **argv)
{
	int		len;
	char	*str;
	char	**strs;

	if (argc != 2)
		ft_error();
	len = 0;
	strs = ft_split(argv[1], ' ');
	while (*strs && ++len)
	{
		str = *strs;
		if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
			ft_error();
		while (*str)
			if (!ft_isvalid(*str++))
				ft_error();
		++strs;
	}
	return (0);
}
