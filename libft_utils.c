/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:38:20 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/10/01 17:04:05 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_error(int status)
{
	ft_putendl_fd("Error", 1);
	if (status)
		exit(status);
	return (status);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

char	*ft_join(char **strs, char *sep)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	while (strs[i])
	{
		if (!i)
			str = ft_strdup(strs[i++]);
		else
		{
			tmp = str;
			str = ft_strjoin(str, sep);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, strs[i++]);
			free(tmp);
		}
	}
	return (str);
}
