# Compile

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
BUFFER = 64

# MINILIBX

MLX_DIR = minilibx-linux
MLX = libmlx.a

# LIBFT

LIBFT_DIR = libft
LIBFT = libft.a

# Path

OBJS_PATH = build/
SRCS_PATH = srcs/
HEADERS_PATH = headers/

SRCS = main.c \
		error/error.c \
		utils/get_next_line.c utils/get_next_line_utils.c \
		utils/utils.c utils/utils_ft.c \
		close.c file.c initialize.c settings.c parsing.c

OBJS = $(addprefix $(OBJS_PATH),$(SRCS:.c=.o))

# Binary

NAME = cube3D

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all :	$(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
		@mkdir -p $(OBJS_PATH) $(addprefix $(OBJS_PATH), error) $(addprefix $(OBJS_PATH), utils)
		${CC} $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) -I $(HEADERS_PATH) -I $(LIBFT_DIR) -I $(MLX_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
