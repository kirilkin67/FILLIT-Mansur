/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:04:10 by btrifle           #+#    #+#             */
/*   Updated: 2019/11/08 19:22:25 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_sol	*create_elem(t_sol *head, int *a)
{
	t_sol *lst;

	lst = (t_sol *)malloc(sizeof(t_sol));
	lst->coord = (int *)malloc(sizeof(int) * 4);
	lst->coord[0] = a[0];
	lst->coord[1] = a[1];
	lst->coord[2] = a[2];
	lst->coord[3] = a[3];
	lst->next = head;
	return (lst);
}

void	reverse_list(t_sol **head)
{
	t_sol *prev;
	t_sol *next;
	t_sol *tmp;

	tmp = *head;
	prev = NULL;
	while (tmp)
	{
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	*head = prev;
}

void	wrap_sol(t_sol **t, int numb, int m)
{
	t_sol	*lst;
	int		*a;
	int		i;
	
	a = (int *)malloc(sizeof(int) * 8);
	set_coord1(a, numb, m);
	set_coord23(a, numb, m);
	set_coord45(a, numb, m);
	set_width_height_total(a, numb);
	lst = NULL;
	lst = create_elem(NULL, a);
	i = 0;
	while (i < a[7] - 1)
	{
		lst = create_elem(lst, next_tetram(a));
		i++;
	}
	*t = lst;
	reverse_list(t);
	free(a);
}

t_sol   *append_next_result_elem(t_sol *head, int *a)
{
	t_sol *new;

	new = (t_sol *)malloc(sizeof(t_sol));
	new->next = head;
	new->coord = a;
	head = new;
	return (head);
}

/*
** forms linked list of all possibilities of given tetra
** then puts the address into t
*/
/*
** entering t - tetramino id, m - field side, a - where to write
*/

void	print_list(t_sol **lst)
{
	t_sol *tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%d %d %d %d->\n", tmp->coord[0],
				tmp->coord[1], tmp->coord[2], tmp->coord[3]);
		tmp = tmp->next;
	}
	printf("NULL\n");

}

int		compare(int na, int nb, int *a, int *b)
{
	int i;
	int j;

	i = 0;
	while (i < na)
	{
		j = 0;
		while (j < nb)
		{
			if (a[i] == b[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void    del_lst(t_sol **lst)
{
	t_sol *tmp1;
	t_sol *tmp2;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1->coord);
		free(tmp1);
		tmp1 = tmp2;
	}
	*lst = NULL;
}

/*
 ** there are two arrays int *a, int *b. Number of items
 ** are at 0'th place.
 ** we need to create a new list.
 ** and free old two arrays
 */

int     *append_two_int_lists(int na, int nb, int *a, int *b)
{
	int *c;
	int i;
	int j;

	if (na == 0 && nb == 0)
		return (NULL);
	c = (int *)malloc(sizeof(int) * (na + nb));
	i = -1;
	while (++i < na)
		c[i] = a[i];
	j = i;
	i = -1;
	while (++i < nb)
		c[j + i] = b[i];
	return (c);
}

/*
 ** input: res, field size m, current nummer van tetram,
 ** and the the order of collision which is k.
 ** function looks the collision of res and no.
 ** it produces new res and frees the old one
 */

t_sol   *collide(t_sol *res, int numb, int m, int k)
{
	int *a;
	int *help;
	t_sol *head; //this is created from numb
	t_sol *tmp;
	t_sol *new_res; //new res
	int c;

	new_res = NULL;
	if (k == 0)
	{
		wrap_sol(&head, numb, m);
		return (head);
	}
	else
	{		
		wrap_sol(&head, numb, m);
	//	printf("HERE!");
	//	print_list(&res);
		while (res)
		{
			tmp = head;
			while (tmp)
			{
				c = compare(4 * k, 4, res->coord, tmp->coord);
			//	printf("%d %d, %d %d, %d\n", res->coord[0], res->coord[1], tmp->coord[0], tmp->coord[1], c);
				if (c == 0)
				{
					help = append_two_int_lists(4 * k, 4, res->coord, tmp->coord);
					new_res = append_next_result_elem(new_res, help);
				}
				tmp = tmp->next;
			}
			res = res->next;
		}
	}
//    del_lst(&head);
//	del_lst(&res);
    reverse_list(&new_res);
	return (new_res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	char	*p;
	size_t	i;
	size_t	n;

	i = 0;
	p = (char *)s1;
	while (p[++i])
		;
	n = i;
	if (!(tmp = (char *)malloc(sizeof(char ) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = p[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}