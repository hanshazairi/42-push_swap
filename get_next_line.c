/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:46:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/10/01 12:58:06 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	gnl_read(char *buf, char **factory)
{
	int		i;
	char	*tmp;

	if (!*factory || !ft_strchr(*factory, '\n'))
	{
		i = read(0, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!*factory)
				*factory = ft_strdup(buf);
			else
			{
				tmp = *factory;
				*factory = ft_strjoin(*factory, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(0, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*gnl_process(char **factory)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*factory)
		return (0);
	if (!ft_strchr(*factory, '\n'))
	{
		ret = ft_strdup(*factory);
		free(*factory);
		*factory = 0;
		return (ret);
	}
	i = ft_strlen(*factory);
	j = ft_strlen(ft_strchr(*factory, '\n'));
	ret = ft_substr(*factory, 0, i - j + 1);
	tmp = *factory;
	*factory = ft_substr(ft_strchr(*factory, '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line(char **factory)
{
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	gnl_read(buf, factory);
	return (gnl_process(factory));
}
