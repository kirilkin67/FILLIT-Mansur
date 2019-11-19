/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_tetram.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:57:35 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/16 20:59:48 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_one_tetramino(int j, int *data, int *tetram)
{
	int	m;

	m = tetram[1];
	ft_set_coord1(tetram + 2 + 8 * j, data[j], m);
	ft_set_coord23(tetram + 2 + 8 * j, data[j], m);
	ft_set_coord4(tetram + 2 + 8 * j, data[j], m);
	ft_set_width_height_total(tetram + 2 + 8 * j, data[j], m);
}

void	ft_next_tetram(int j, int *a)
{
	int	diff;
	int	m;
	int	i;

	m = a[1];
	i = 8 * j + 2;
	if ((a[i] + 1) % m == 0)
		diff = a[i + 4];
	else
		diff = 1;
	a[i] = a[i] + diff;
	a[i + 1] = a[i + 1] + diff;
	a[i + 2] = a[i + 2] + diff;
	a[i + 3] = a[i + 3] + diff;
}
