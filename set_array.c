/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:53:00 by btrifle           #+#    #+#             */
/*   Updated: 2019/11/08 19:22:35 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_coord1(int *a, int t, int m)
{
	if (t == 103 || t == 111 || t == 110 || t == 105 || t == 114 || t == 119)
		a[0] = 2;
	else if (t == 101)
		a[0] = 1;
	else if (t == 108 || t == 106 || t == 109 || t == 112 || t == 118)
		a[0] = 3;
	else if (t == 102)
		a[0] = 4;
	else if (t == 107 || t == 113 || t == 116)
		a[0] = 3 + m;
	else if (t == 115 || t == 117)
		a[0] = 2 + m;
	else if (t == 104)
		a[0] = 2 + 2 * m;
}

void	set_coord23(int *a, int t, int m)
{
	if (t == 101 || t == 103 || t == 110 || t == 114 || t == 119 ||
			t == 108 || t == 106 || t == 112 || t == 107 ||
			t == 116 || t == 115 || t == 117 || t == 104)
		a[1] = 1 + m;
	else if (t == 111 || t == 105 || t == 118 || t == 113)
		a[1] = 2 + m;
	else if (t == 102)
		a[1] = 2;
	else if (t == 109)
		a[1] = 3 + m;
	if (t == 102 || t == 103 || t == 111 || t == 110 || t == 108
			|| t == 109 || t == 118 || t == 107 || t == 113 ||
			t == 115 || t == 117 || t == 104)
		a[2] = 1;
	else if (t == 101 || t == 105 || t == 114)
		a[2] = 1 + 2 * m;
	else if (t == 119 || t == 106 || t == 112 || t == 116)
		a[2] = 2 + m;
}

void	set_coord45(int *a, int t, int m)
{
	if (t == 108 || t == 109 || t == 112 || t == 113 || t == 116 || t == 118)
		a[3] = 2;
	else if (t == 101)
		a[3] = 1 + 3 * m;
	else if (t == 103 || t == 114 || t == 107)
		a[3] = 2 + m;
	else if (t == 111 || t == 105 || t == 119 || t == 115)
		a[3] = 2 + 2 * m;
	else if (t == 102)
		a[3] = 3;
	else if (t == 104 || t == 110 || t == 117)
		a[3] = 1 + 2 * m;
	else if (t == 106)
		a[3] = 3 + m;
	a[4] = m;
}

void	set_width_height_total(int *a, int t)
{
	if (t == 101)
		a[5] = 1;
	else if (t == 102)
		a[5] = 4;
	else if (t == 103 || t == 104 || t == 105 || t == 110 || t == 111
			|| t == 114 || t == 115 || t == 117 || t == 119)
		a[5] = 2;
	else if (t == 106 || t == 107 || t == 108 || t == 109 || t == 112
			|| t == 113 || t == 116 || t == 118)
		a[5] = 3;
	if (t == 102)
		a[6] = 1;
	else if (t == 101)
		a[6] = 4;
	else if (t == 103 || t == 106 || t == 107 || t == 108 || t == 109
			|| t == 112 || t == 113 || t == 116 || t == 118)
		a[6] = 2;
	else if (t == 104 || t == 105 || t == 110 || t == 111 || t == 114
			|| t == 115 || t == 117 || t == 119)
		a[6] = 3;
	a[7] = (a[4] - a[5] + 1) * (a[4] - a[6] + 1);
}

/*
 ** enters the coordinates of current tetramino as an array;
 ** exits the next tetramino integers as the same but changed array;
 */

int		*next_tetram(int *a)
{
	int diff;

	if (a[0] % a[4] == 0)
		diff = a[5];
	else
		diff = 1;
	a[0] = a[0] + diff;
	a[1] = a[1] + diff;
	a[2] = a[2] + diff;
	a[3] = a[3] + diff;
	return (a);
}
