CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = gnl.o gnl_utils.o draw.o main.o \
	move.o parsing.o utils.o dfs.o \
	print.o utils2.o
NAME = so_long

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY: all clean fclean re