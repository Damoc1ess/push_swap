
NAME = push_swap.a

CC = cc

#CFLAGS = -Wall -Wextra -Werror

SRC_C = src/operations/push.c\
			src/operations/reverse_rotate.c\
			src/operations/reverse.c\
			src/operations/rotate.c\
			src/operations/swap.c\
			src/brute.c\
			src/main.c\
			utils/utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) -c
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) src/main.c $(NAME) -o main


clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf *.o
	@rm -rf $(NAME)

re : fclean all
	@rm -rf $(OBJS)
