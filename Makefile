# Compile

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
BUFFER_SIZE = 64

# MINILIBX

MLX_DIR = minilibx-linux
MLX = libmlx.a

# Path

OBJS_PATH = build/
SRCS_PATH = srcs/
HEADERS_PATH = headers/

SRCS = main.c \
		get_next_line.c get_next_line_utils.c \
		utils_ft.c utils.c file.c initialize.c settings.c parsing.c


OBJS = $(addprefix $(OBJS_PATH),$(SRCS:.c=.o))

# Binary

NAME = cube3D

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all :	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
		@mkdir -p $(OBJS_PATH)
		${CC} $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I $(HEADERS_PATH) -I $(MLX_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
