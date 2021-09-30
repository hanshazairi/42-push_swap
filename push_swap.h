/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:59:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/30 17:16:22 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1024

/* libft_utils.c */
int		ft_isint(char *str);
char	*ft_join(char **strs, char *sep);

/* validate.c */
int		convert(char **strs, int **nums);
void	cleanup_1(char **strs);
void	error(void);
void	cleanup_2(t_list *stack, int *nums);

/* instructions.c */
void	run(char *str, t_list **stack_1, t_list **stack_2, int x);

/* sort.c */
void	sort(t_list **stack);

/* sort_utils.c */
int		issorted(t_list *stack);
int		min(int a, int b);
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);

/* sort_big_utils.c */
int		stack_idx_minmax(t_list *stack, int num);
void	find_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);

#endif
