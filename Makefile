# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 11:30:21 by fflamion          #+#    #+#              #
#    Updated: 2024/08/11 14:37:44 by fflamion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

FLAGS	= -Wall -Werror -Wextra
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME	= push_swap

SRC		= main.c \
		src/utils/check_args.c \
		src/utils/check_args_utils.c \
		src/utils/stack.c \
		src/operations/swap.c \
		src/operations/push.c \
		src/operations/rotate.c \
		src/operations/reverse_rotate.c \
		src/utils/sort.c \
		src/utils/algo.c \
		src/utils/finder.c \
		src/utils/get_cost.c \
		src/utils/utils.c \
		src/utils/ft_split.c

OBJ		= $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
