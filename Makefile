C_FILES = create_array.c create_array_utils.c create_file.c free.c ft_strjoin.c error.c ft_strnstr.c main.c parse.c ft_split.c player.c check_path.c images.c ft_calloc.c ft_putnbr_fd.c player_utils.c
O_FILES = $(C_FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
CLINK = -L/usr/include/minilibx-linux/ -lmlx -lX11 -lXext
NAME = so_long

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	$(CC) $(O_FILES) $(CLINK) -o $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
