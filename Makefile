NAME = main.a

EXEC = main

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_C = src/operations/push.c \
        src/operations/reverse_rotate.c \
        src/operations/reverse.c \
        src/operations/rotate.c \
        src/operations/swap.c \
        src/brute.c \
        src/main.c \
        utils/utils.c

OBJS = $(SRC_C:.c=.o)

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS) src/main.c $(NAME) -o $(EXEC)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(EXEC)
	@rm -rf $(NAME)

re: fclean all
