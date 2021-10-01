/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:46:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/10/01 14:21:29 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

static int	parse(char *str, t_list **stack_1, t_list **stack_2)
{
	int	len;
	int	(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (error(0));
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && (!f(str, "sa", 2)
				|| !f(str, "ra", 2))))
		run(str, stack_1, 0, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && (!f(str, "sb", 2)
				|| !f(str, "rb", 2))))
		run(str, stack_2, 0, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && (!f(str, "ss", 2)
				|| !f(str, "pb", 2) || !f(str, "rr", 2))))
		run(str, stack_1, stack_2, -1);
	else if (!f(str, "pa", 2))
		run(str, stack_2, stack_1, -1);
	else
		return (error(0));
	return (1);
}

static void	sort_check(t_list **stack_a)
{
	static char	*factory;
	char		*cmd;
	t_list		*stack_b;

	stack_b = 0;
	while (1)
	{
		cmd = get_next_line(&factory);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (!parse(cmd, stack_a, &stack_b))
		{
			free(factory);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (issorted(*stack_a) && !ft_lstsize(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

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
		sort_check(&stack);
		free(nums);
		cleanup_2(stack);
	}
	return (0);
}
