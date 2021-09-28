/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:59:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/28 17:07:16 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int		issorted(t_list *stack);
int		min(int a, int b);
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
int		stack_idx_minmax(t_list *stack, int num);
void	sort(t_list **stack);
void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);
void	run(char *str, t_list **stack_1, t_list **stack_2, int x);

#endif
