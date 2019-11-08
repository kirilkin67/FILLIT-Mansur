/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:58:24 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/08 19:28:04 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFF_SIZE 546
# define MESSAGE1 "USAGE: ./fillit <name file.txt>\n"
# define MESSAGE2 "Too many arguments.\nUSAGE: ./fillit <name file.txt>\n"

typedef struct		s_fillit
{
	int				id;
	int				tetrimino;
	int				tetr_puzzle;
	void			*path;
}					t_fillit;

typedef struct		s_sol
{
	int				*coord;
	struct s_sol	*next;
}					t_sol;

int					ft_tetrimino_validation(char *str);
char				*ft_itoa_base (int value, int base);
int					*ft_validation(char *str);
int					*ft_array_tetras(char *str);
int					ft_min_map(int *tetros, size_t len_tab);
void	set_coord1(int *a, int t, int m);
void	set_coord23(int *a, int t, int m);
void	set_coord45(int *a, int t, int m);
void	set_width_height_total(int *a, int t);
int		*next_tetram(int *a);
t_sol	*create_elem(t_sol *head, int *a);
t_sol	*add_next_result_elem(t_sol *head, int *a);
void	wrap_sol(t_sol **t, int numb, int m);
void	print_list(t_sol **t);
void	reverse_list(t_sol **t);
void	print_list(t_sol **t);
int		compare(int na, int nb, int *a, int *b);
void	del_lst(t_sol **t);
int		*append_two_int_lists(int na, int nb, int *a, int *b);
t_sol	*append_next_result_elem(t_sol *head, int *a);
t_sol	*collide(t_sol *res, int numb, int m, int k);
void	display_solution_line(t_sol *lst, int m, int n);


#endif
