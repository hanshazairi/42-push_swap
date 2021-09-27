/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:05:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/11 00:37:21 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sx(t_list **stack);
void	rx(t_list **stack);
void	rrx(t_list **stack);

void	sort_132(t_list **stack)
{
	sx(stack);
	ft_putendl_fd("sa", 1);
	rx(stack);
	ft_putendl_fd("ra", 1);
}

void	sort_213(t_list **stack)
{
	sx(stack);
	ft_putendl_fd("sa", 1);
}

void	sort_231(t_list **stack)
{
	rrx(stack);
	ft_putendl_fd("rra", 1);
}

void	sort_312(t_list **stack)
{
	rx(stack);
	ft_putendl_fd("ra", 1);
}

void	sort_321(t_list **stack)
{
	sx(stack);
	ft_putendl_fd("sa", 1);
	rrx(stack);
	ft_putendl_fd("rra", 1);
}
