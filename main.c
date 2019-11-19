/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:50:45 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/18 14:16:04 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_fillit_read(char *dest)
{
	char		bufer[BUFF_SIZE + 1];
	char		*str;
	ssize_t		ret;
	int			fd;

	fd = open(dest, O_RDONLY);
	ret = read(fd, bufer, BUFF_SIZE);
	if (ret == -1 || ret < 20 || ((ret + 1) % 21) != 0 || ret > 545)
	{
		ft_putendl("error");
		return (NULL);
	}
	bufer[ret] = '\0';
	str = ft_strdup(bufer);
	close(fd);
	return (str);
}

int			main(int argc, char **argv)
{
	static char	*str;
	size_t		len_array;
	int			*tetras;

	if (argc != 2)
	{
		ft_putstr(MESSAGE1);
		return (0);
	}
	if ((str = ft_fillit_read(argv[1])) != NULL)
	{
		len_array = (ft_strlen(str) + 1) / 21;
		tetras = ft_validation(str, len_array);
		if (tetras)
		{
			ft_use_fillit(len_array, tetras);
			free(tetras);
			free(str);
		}
	}
	return (0);
}
