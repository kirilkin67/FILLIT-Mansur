/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_fillit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:58:03 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/16 21:31:01 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_board(int j, int *tetram, int *board)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		board[4 * j + i] = tetram[8 * j + i + 2];
		i++;
	}
}

void	ft_get_next_j(int *jj, int *tetram, int *data)
{
	int	k;

	tetram[8 * (*jj) + 8] += 1;
	ft_next_tetram(*jj, tetram);
	k = *jj;
	while (k >= 0)
	{
		if (tetram[8 * k + 8] == tetram[8 * k + 9])
		{
			tetram[8 * k + 8] = 0;
			ft_set_one_tetramino(k, data, tetram);
			if (k > 0)
			{
				tetram[8 * (k - 1) + 8] += 1;
				ft_next_tetram(k - 1, tetram);
				*jj = k - 1;
			}
		}
		else
			break ;
		k--;
	}
	if (k == -1)
		ft_get_new_size(jj, tetram, data);
}

void	ft_fillit(int *jj, int *tetram, int *board, int *data)
{
	int j;
	int c;

	j = *jj;
	c = ft_check_current_tetramino(j, tetram, board);
	if (c)
	{
		ft_fill_board(j, tetram, board);
		*jj = *jj + 1;
	}
	else
		ft_get_next_j(jj, tetram, data);
	return ;
}

void	ft_display_square(char *square, char *letters, int *tetram, int *board)
{
	int i;
	int j;

	i = -1;
	while (++i < tetram[1] * tetram[1])
		square[i] = '.';
	j = 0;
	i = 0;
	while (i < 4 * tetram[0])
	{
		square[board[i]] = letters[j];
		if ((i + 1) % 4 == 0)
			j++;
		i++;
	}
	i = -1;
	while (++i < tetram[1] * tetram[1])
	{
		ft_putchar(square[i]);
		if ((i + 1) % tetram[1] == 0)
			ft_putchar('\n');
	}
}

void	ft_use_fillit(int am, int *data)
{
	int		*tetram;
	int		*board;
	int		j;
	char	*letters;
	char	*square;

	letters = ft_strdup("ABCDEFGHIJKLMNOPQRTSUVWXYZ");
	tetram = (int *)malloc(sizeof(int) * (8 * am + 2));
	tetram[0] = am;
	tetram[1] = ft_get_final_size(am, data);
	j = -1;
	while (++j < tetram[0])
		ft_set_one_tetramino(j, data, tetram);
	board = (int *)malloc(sizeof(int) * 4 * am);
	j = -1;
	while (++j < 4 * tetram[0])
		board[j] = -1;
	j = 0;
	while (j != am)
		ft_fillit(&j, tetram, board, data);
	square = (char *)malloc(sizeof(char) * tetram[1] * tetram[1]);
	ft_display_square(square, letters, tetram, board);
	free(letters);
	free(square);
	free(tetram);
	free(board);
}
