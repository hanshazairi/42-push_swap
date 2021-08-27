/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/27 14:55:22 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(void);
int		validate1(char **strs);
int		*validate2(char **strs, int len);

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	int		*nums;
	char	**strs;

	if (argc != 2)
		ft_error();
	strs = ft_split(argv[1], ' ');
	len = validate1(strs);
	nums = validate2(strs, len);
	i = 0;
	while (nums[i])
	{
		ft_putnbr_fd(nums[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	free(nums);
	free(strs);
	return (0);
}
