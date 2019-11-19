# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 20:07:08 by wrhett            #+#    #+#              #
#    Updated: 2019/11/19 11:54:08 by wrhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_validation.c ft_tetrimino_validation.c \
	ft_get_size.c ft_next_tetram.c ft_use_fillit.c ft_set_array.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = fillit.h

LIBFT = $(LIBFT_PATH) libft.a
LIBFT_PATH = libft/

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
		@gcc -o $(NAME) $(OBJECTS) -I $(LIBFT_PATH)includes -L \
		$(LIBFT_PATH) -lft
		@echo "\033[32m$(NAME) was created\033[0m"

$(OBJECTS): %.o: %.c
		@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)

test:	all
		@./fillit test
clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
