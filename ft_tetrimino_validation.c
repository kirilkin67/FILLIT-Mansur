/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:51:59 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/08 15:52:48 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const int g_tab[19] = {34952, 61440, 52224, 35008, 17600, 11776, 36352, 59392,
	57856, 51328, 50240, 27648, 50688, 19584, 35904, 19968, 35968, 58368,
	19520};

static int	is_tetrimino(int tetr)
{
	int n;

	n = 0;
	while (n <= 19)
	{
		if (tetr != g_tab[n])
			n += 1;
		else
			return (1);
	}
	return (0);
}

static int	ft_atoi_binary(char *str)
{
	unsigned int	num;
	int				n;

	num = 0;
	n = 0;
	while (str[n] != '\0' && n < 19)
	{
		if (str[n] == '\n')
			n += 1;
		num = num * 2 + (str[n] - '0');
		n += 1;
	}
	return (num);
}

int			ft_tetrimino_validation(char *str)
{
	int	tetrimino;

	tetrimino = ft_atoi_binary(str);
	while (tetrimino <= 61440)
	{
		if (is_tetrimino(tetrimino) == 1)
			return (tetrimino);
		else
		{
			if ((tetrimino & (1 << 3)) || (tetrimino & (1 << 7)) ||
			(tetrimino & (1 << 11)))
				tetrimino = tetrimino << 4;
			else
				tetrimino = tetrimino << 1;
		}
	}
	return (0);
}

int			*ft_array_tetras(char *str)
{
	size_t	len_array;
	int		*tetras;
	int		tetr;
	int		m;
	int		n;

	len_array = (ft_strlen(str) + 1) / 21;
	tetras = (int *)malloc(sizeof(int) * (len_array + 1));
	if (tetras == NULL)
		return (NULL);
	tetras[0] = len_array;
	n = 1;
	while (*str)
	{
		tetr = ft_tetrimino_validation(str);
		m = 0;
		while (tetr != g_tab[m])
			m += 1;
		tetras[n] = 101 + m;
		n += 1;
		str += 21;
	}
	return (tetras);
}
