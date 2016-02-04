# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 08:34:59 by frmarinh          #+#    #+#              #
#    Updated: 2016/01/25 01:07:27 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS_NAME = main.c check_size.c utils.c print_columns.c handle_keys.c select.c read_all_char.c

LIB_FOLDER = libft/

O_NAME = $(SRCS_NAME:.c=.o)

FLAGS = -Wall -Wextra -Werror -ggdb -O3

INCLUDE_FOLDER = libft/includes/

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@gcc $(FLAGS) -I $(INCLUDE_FOLDER) -c $(SRCS_NAME)
	@gcc -o $(NAME) $(O_NAME) -L $(LIB_FOLDER) -lft

clean:
	@rm -rf $(O_NAME)

fclean: clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
