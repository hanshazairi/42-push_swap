/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:46:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/30 17:27:12 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "push_swap.h"

static char	**getcmds(void)
{
	int		i;
	char	*buf;
	char	*str;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	i = read(0, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = 0;
		if (!str)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		i = read(0, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_split(str, '\n'));
}

static int	isvalidcmd(char **cmds)
{
	int		len;
	char	*cmd;

	while (*cmds)
	{
		cmd = *cmds++;
		len = ft_strlen(cmd);
		if (ft_strncmp(cmd, "sa", len) && ft_strncmp(cmd, "sb", len)
			&& ft_strncmp(cmd, "ss", len) && ft_strncmp(cmd, "pa", len)
			&& ft_strncmp(cmd, "pb", len) && ft_strncmp(cmd, "ra", len)
			&& ft_strncmp(cmd, "rb", len) && ft_strncmp(cmd, "rr", len)
			&& ft_strncmp(cmd, "rra", len) && ft_strncmp(cmd, "rrb", len)
			&& ft_strncmp(cmd, "rrr", len))
			return (0);
	}
	return (1);
}

static void	run_helper(char *cmd, t_list **stack_1, t_list **stack_2)
{	
	if (!ft_strncmp(cmd, "rra", 3) || !ft_strncmp(cmd, "sa", 2)
		|| !ft_strncmp(cmd, "ra", 2))
		run(cmd, stack_1, 0, -1);
	else if (!ft_strncmp(cmd, "rrb", 3) || !ft_strncmp(cmd, "sb", 2)
		|| !ft_strncmp(cmd, "rb", 2))
		run(cmd, stack_2, 0, -1);
	else if (!ft_strncmp(cmd, "rrr", 3) || !ft_strncmp(cmd, "ss", 2)
		|| !ft_strncmp(cmd, "pb", 2) || !ft_strncmp(cmd, "rr", 2))
		run(cmd, stack_1, stack_2, -1);
	else if (!ft_strncmp(cmd, "pa", 2))
		run(cmd, stack_2, stack_1, -1);
}

static void	sort_check(t_list **stack_a)
{
	int		i;
	char	**cmds;
	t_list	*stack_b;

	i = 0;
	cmds = getcmds();
	stack_b = 0;
	if (isvalidcmd(cmds))
	{
		while (cmds[i])
		{
			run_helper(cmds[i++], stack_a, &stack_b);
			free(cmds[i]);
		}
	}
	else
	{
		error();
		return ;
	}
	free(cmds);
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
			error();
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(&nums[len]));
		sort_check(&stack);
		cleanup_2(stack, nums);
	}
	return (0);
}
