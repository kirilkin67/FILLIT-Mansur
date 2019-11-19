/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:58:24 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/16 21:41:22 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 546
# define MESSAGE1 "usage: (1 source file) ./fillit <name file.txt>\n"

int		ft_tetrimino_validation(char *str);
int		*ft_validation(char *str, size_t len_array);
int		*ft_array_tetras(char *str, size_t len_array);
void	ft_set_coord1(int *a, int t, int m);
void	ft_set_coord23(int *a, int t, int m);
void	ft_set_coord4(int *a, int t, int m);
void	ft_set_width_height_total(int *a, int t, int m);
void	ft_next_tetram(int j, int *a);
void	ft_set_one_tetramino(int j, int *data, int *tetram);
int		ft_check_current_tetramino(int j, int *tetram, int *board);
void	ft_fill_board(int j, int *tetram, int *board);
void	ft_get_next_j(int *jj, int *tetram, int *data);
void	ft_fillit(int *jj, int *tetram, int *board, int *data);
int		ft_get_size(int num);
void	ft_get_new_size(int *jj, int *tetram, int *data);
int		ft_get_final_size(int am, int *data);
void	ft_use_fillit(int am, int *data);

#endif
