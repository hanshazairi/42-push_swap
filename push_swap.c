/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:17:50 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/27 23:44:37 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"

void	ft_error(void);
int		validate1(char **strs);
int		*validate2(char **strs, int len);

int	main(int argc, char **argv)
{
	int		len;
	int		*nums;
	char	**strs;
	t_list	*head;
	t_list	*tmp;

	if (argc != 2)
		ft_error();
	strs = ft_split(argv[1], ' ');
	len = validate1(strs);
	nums = validate2(strs, len);
	while (len--)
		ft_lstadd_front(&head, ft_lstnew(&nums[len]));
	free(nums);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	while (strs[++len])
		free(strs[len]);
	free(strs);
	return (0);
}
