/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/28 00:42:21 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(void);
int		validate1(char **strs);
int		*validate2(char **strs, int len);
void	ft_mergesort(t_list **stack, int depth);

int	main(int argc, char **argv)
{
	int		len;
	int		*nums;
	char	**strs;
	t_list	*stack;
	t_list	*tmp;

	if (argc != 2)
		ft_error();
	strs = ft_split(argv[1], ' ');
	len = validate1(strs);
	nums = validate2(strs, len);
	while (len--)
		ft_lstadd_front(&stack, ft_lstnew(&nums[len]));
	ft_mergesort(&stack, 0);
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
	return (0);
}
