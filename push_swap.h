/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:59:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/27 20:09:41 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		issorted(t_list *stack);
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
int		stack_idx_mid(t_list *stack, int num);
int		stack_idx_minmax(t_list *stack, int num);
void	sx(t_list **stack);
void	px(t_list **stack_a, t_list **stack_b);
void	rx(t_list **stack);
void	rrx(t_list **stack);
void	sort(t_list **stack);
void	sort_132(t_list **stack);
void	sort_213(t_list **stack);
void	sort_231(t_list **stack);
void	sort_312(t_list **stack);
void	sort_321(t_list **stack);
void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate(t_list **stack_a, t_list **stack_b, int a, int b);

#endif
