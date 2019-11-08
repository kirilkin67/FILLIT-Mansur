#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_sol
{
	int				*coord;
	struct s_sol	*next;
}					t_sol;

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

#endif
