#include "fillit.h"

static char		*ft_fillit_read(const int fd)
{
	char		bufer[BUFF_SIZE + 1];
	static char	*str;
	ssize_t		ret;

	ret = read(fd, bufer, BUFF_SIZE);
	if (ret == -1)
	{
		ft_putendl("ERROR: the file does not read."); // delete
		return (NULL);
	}
	if (ret < 20 || ((ret + 1) % 21) != 0 || ret > 545)
	{
		ft_putendl("error");
		return (NULL);
	}
	bufer[ret] = '\0';
	str = ft_strdup(bufer);
	return (str);
}

int		ft_min_map(int *tetras, size_t len_tab)
{
	int nb;
	int m;

	nb = 4 * len_tab;
	m = 1;
	while ((m * m) < nb)
		m += 1;
	if (tetras[1] == 103 && len_tab == 1)
		m = 2;
	else if ((tetras[1] == 101 || tetras[1] == 102 || tetras[2] == 101
	|| tetras[2] == 102) && (len_tab == 1 || len_tab == 2))
		m = 4;
	else if (len_tab == 1)
			m = 3;
	return (m);
}

void display_solution_line(t_sol *lst, int m, int n)
{
	char *arr;
	int field;
	int i;
	int j;
	char *letters;

	letters = ft_strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	field = m * m;
	arr = (char *)malloc(sizeof(char) * field);
	arr[field] = '\0';
	i = -1;
	while (++i < field)
		arr[i] = '.';
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((i + 1) % m == 0)
			j++;
		arr[lst->coord[i] - 1] = letters[j];
		i++;		
	}
	i = -1;
	while (++i < field)
	{
		ft_putchar(arr[i]);
		if ((i + 1) % m == 0)
			ft_putchar('\n');
	}
	free(letters);
}

void form_and_display_solution(int *tetras, int m)
{
	t_sol *head1;
	t_sol *head2;
	int k;
	
	while (1)
	{
		k = 0;
		while (k < tetras[0])
		{
			head2 = collide(head1, tetras[k + 1], m, k);
			if (k)
				del_lst(&head1);
			head1 = head2;
			k++;
		}
		if (head2 == NULL)
			m++;
		else
			break ;
	}
	display_solution_line(head2, m, tetras[0] * 4);
}

int		main(int argc, char **argv)
{
	static char *str;
	int			fd;
	size_t		len_tab;
	int			*tetras;

	if (argc != 2)
	{
		ft_putstr(MESSAGE1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ERROR cannot open file or file name is INCORRECT.\n");
		return (0);
	}
	if ((str = ft_fillit_read(fd)) != NULL)
	{
		len_tab = (ft_strlen(str) + 1) / 21;
		tetras = ft_validation(str);
		if (tetras)
		{
			size_t n = 0;
			while (n < (len_tab +1))
			{
				printf("TETRAS new - %d\n", tetras[n]);
				n += 1;
			}
			form_and_display_solution(tetras, ft_min_map(tetras, len_tab));
		}
	}
	close(fd);
	return (0);
}
