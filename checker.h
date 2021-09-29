/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:19:01 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/09/29 14:36:27 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 3

int		isint(char *str);
int		hasdup(int *nums, int len);
void	cleanup(t_list *stack, int *nums);
void	error(t_list *stack, int *nums);
int		issorted(t_list *stack);
void	run(char *str, t_list **stack_1, t_list **stack_2, int x);

#endif
