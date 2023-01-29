NAME = fractol

CFLAGS = -Wall -Wextra -Werror

SRCS = mandelbrot.c julia.c tricorn.c main.c utils/iterations.c utils/src.c utils/libft.c utils/events.c utils/zoom.c \

OBJS = $(SRCS:.c=.o)

HEADER = fractol.h

all: $(NAME)

CC = cc

MLK = -Wall -Wextra -Werror -Imlx -c $< -o

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f	$(NAME)

re:  fclean all 
