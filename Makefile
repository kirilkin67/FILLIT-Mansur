# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 20:07:08 by wrhett            #+#    #+#              #
#    Updated: 2019/11/08 19:31:46 by wrhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_validation.c ft_tetrimino_validation.c \
	set_array.c set_list.c
		
OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = fillit.h

LIBFT = $(LIBFT_PATH) libft.a
LIBFT_PATH = libft/

#FLAGS = -Wall -Wextra -Werror

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

#$> make -C libft/ fclean && make -C libft/
#$> gcc $(FLAGS) -I libft/includes -o get_next_line.o -c get_next_line.c
#$> clang $(FLAGS) -I libft/includes -o main.o -c main.c
			  #NAME
#$> clang -o test_gnl  get_next_line.o -I libft/includes -L libft/ -lft
