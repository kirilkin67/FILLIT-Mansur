/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:49:36 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/08 16:22:52 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_character(char *str)
{
	while (*str != '\0')
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		if (*str == '.')
			*str = '0';
		if (*str == '#')
			*str = '1';
		str += 1;
	}
	return (1);
}

static int		valid_block(char *str)
{
	int	line;

	while (*str)
	{
		line = 0;
		while (line != 4)
		{
			if ((ft_strchr(str, '\n') - str) == 4)
			{
				line += 1;
				str = ft_strchr(str, '\n') + 1;
			}
			else
				return (0);
		}
		if (*str != '\n' && *str != '\0')
			return (0);
		else if (*str == '\n')
			str += 1;
	}
	return (1);
}

static int		valid_tetrimino(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (ft_tetrimino_validation(tmp) == 0)
			return (0);
		else
			tmp += 21;
	}
	return (1);
}

int		*ft_validation(char *str)
{
	int		*tetras;

	if (str && valid_character(str) && valid_block(str) &&
	valid_tetrimino(str))
	{
		tetras = ft_array_tetras(str);
		return (tetras);
	}
	else
		ft_putendl("error");
	return (NULL);
}
