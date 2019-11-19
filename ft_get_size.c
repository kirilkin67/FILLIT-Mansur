/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:58:25 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/16 20:58:26 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_current_tetramino(int j, int *tetram, int *board)
{
	int i1;
	int i2;

	i1 = 0;
	while (i1 < 4)
	{
		i2 = 0;
		while (i2 < 4 * j)
		{
			if (tetram[8 * j + i1 + 2] == board[i2])
				return (0);
			i2++;
		}
		i1++;
	}
	return (1);
}

int		ft_get_size(int num)
{
	if (num == 2)
		return (3);
	else if (num == 3 || num == 4)
		return (4);
	else if (num == 5 || num == 6)
		return (5);
	else if (num == 7 || num == 8 || num == 9)
		return (6);
	else if (num == 10 || num == 11 || num == 12)
		return (7);
	else if (num == 13 || num == 14 || num == 15 || num == 16)
		return (8);
	else if (num == 17 || num == 18 || num == 19 || num == 20)
		return (9);
	else if (num == 21 || num == 22 || num == 23 || num == 24 || num == 25)
		return (10);
	else
		return (11);
}

int		ft_get_final_size(int am, int *data)
{
	if (am == 1)
	{
		if (data[0] == 103)
			return (2);
		else if (data[0] == 101 || data[0] == 102)
			return (4);
		else
			return (3);
	}
	else if (am == 2)
	{
		if (data[0] == 101 || data[0] == 102
		|| data[1] == 101 || data[1] == 102)
			return (4);
		else
			return (3);
	}
	else
		return (ft_get_size(am));
	return (0);
}

void	ft_get_new_size(int *jj, int *tetram, int *data)
{
	int i;

	*jj = 0;
	tetram[1] += 1;
	i = -1;
	while (++i < tetram[0])
		ft_set_one_tetramino(i, data, tetram);
}
