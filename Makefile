NAME = push_swap

EXEC = main

CC = cc

CFLAGS = -g3

SRC_C = src/operations/push.c \
        src/operations/reverse_rotate.c \
        src/operations/rotate.c \
        src/operations/swap.c \
        src/brute.c \
        src/main.c \
        utils/util_1.c\
		utils/util_2.c\
		utils/ft_split.c

OBJS = $(SRC_C:.c=.o)

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) src/main.c $(NAME) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(EXEC)
	rm -rf $(NAME)

re: fclean all
	rm -rf $(OBJS)

.SILENT: