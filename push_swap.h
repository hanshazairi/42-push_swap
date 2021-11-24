/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:59:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/11/24 20:50:11 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 5

# include "libft/libft.h"

/* push_swap_utils.c */
int		split_argv(char ***strs, char **argv, char *sep);
int		is_valid(char **strs);
int		is_sorted(t_list *stack);

/* instructions.c */
void	run(char *str, t_list **stack_1, t_list **stack_2, int x);

/* sort.c */
void	sort(t_list **stack);

/* sort_utils.c */
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
int		min(int a, int b);

/* sort_big_utils.c */
int		stack_idx_minmax(t_list *stack, int num);
void	get_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);

/* get_next_line.c */
char	*get_next_line(char **str);

#endif
