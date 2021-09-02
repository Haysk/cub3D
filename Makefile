# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 17:42:20 by adylewsk          #+#    #+#              #
#    Updated: 2021/09/02 03:09:45 by adylewsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS = cub3D_bonus

# Compile

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
BUFFER = 64

# MINILIBX

MLX_DIR = minilibx-linux
MLX = libmlx_linux.a

# LIBFT

LIBFT_DIR = libft
LIBFT = libft.a

# Path

DIR_BUILD = build/
DIR_SRCS = srcs/
DIR_BONUS = srcs_bonus/
DIR_HEADERS = headers/


SRC = main.c \
		error.c \
		utils/utils.c utils/utils_ft.c \
		close.c file.c data_initialization.c settings.c check.c \
		get_map.c game/loop.c game/setup.c game/input.c game/update.c \
		game/render.c game/put_pixel.c game/ray.c game/intersection.c \
		game/walls.c

SRC_BONUS = main_bonus.c \
		error_bonus.c \
		utils_bonus/utils_bonus.c utils_bonus/utils_ft_bonus.c \
		close_bonus.c file_bonus.c data_initialization_bonus.c settings_bonus.c check_bonus.c \
		get_map_bonus.c game_bonus/loop_bonus.c game_bonus/setup_bonus.c game_bonus/input_bonus.c game_bonus/update_bonus.c \
		game_bonus/render_bonus.c game_bonus/put_pixel_bonus.c game_bonus/ray_bonus.c game_bonus/intersection_bonus.c \
		game_bonus/walls_bonus.c

SRCS = $(addprefix $(DIR_SRCS), $(SRC:.c=.o))

SRCS_BONUS = $(addprefix $(DIR_BONUS), $(SRC_BONUS:.c=.o))

OBJS = $(addprefix $(DIR_BUILD), $(patsubst %.c,%.o,$(SRCS)))

OBJS_BONUS = $(addprefix $(DIR_BUILD), $(patsubst %.c,%.o,$(SRCS_BONUS)))

Black = \e[1;30m
Red = \e[1;31m
Green = \e[1;32m
Yellow = \e[1;33m
Blue = \e[1;34m
Magenta = \e[1;35m
Cyan = \e[1;36m
Light_gray = \e[1;37m
Dark_gray = \e[1;90m
White = \e[1;97m
End = \e[1;0m

all :	$(NAME)
		@echo "$(Green)__________$(NAME) OK____________$(End)"

bonus : $(BONUS)
		@echo "$(Green)__________$(BONUS) OK____________$(End)"


$(LIBFT) :
	@make -sC $(LIBFT_DIR)

$(MLX) :
	@make -sC $(MLX_DIR)

$(DIR_BUILD)% :
	@mkdir -p $@
	@echo "$(Blue)$@ Created$(End)"

.SECONDEXPANSION:


$(NAME) :$(LIBFT) $(MLX) start $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
	@echo "$(Green)MAKE\033[5C->\033[5C$@$(End)"

$(BONUS) :$(LIBFT) $(MLX) start $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
	@echo "$(Green)MAKE\033[5C->\033[5C$@$(End)"

$(OBJS) : $(DIR_BUILD)%.o:%.c | $$(@D)/
		@mkdir -p $(DIR_BUILD)
		@echo "$(Cyan)BUILDING\033[5C->\033[5C$<$(End)"
		@${CC} $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) -I $(DIR_HEADERS) -I $(LIBFT_DIR) -I $(MLX_DIR) -c $< -o $@

$(OBJS_BONUS) : $(DIR_BUILD)%.o:%.c | $$(@D)/
		@mkdir -p $(DIR_BUILD)
		@echo "$(Cyan)BUILDING\033[5C->\033[5C$<$(End)"
		@${CC} $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) -I $(DIR_HEADERS) -I $(LIBFT_DIR) -I $(MLX_DIR) -c $< -o $@

start:
	@echo "$(Green)__________$(NAME)____________$(End)"

clean :
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(DIR_BUILD)
	@echo "$(Red)REMOVE CUB3D\033[3C->\033[5C$(DIR_BUILD)$(End)"



fclean :
	@make fclean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@rm -rf $(DIR_BUILD)
	@echo "$(Red)REMOVE CUB3D\033[3C->\033[5C$(DIR_BUILD)$(End)"
	@echo "$(Red)REMOVE CUB3D\033[3C->\033[5C$(NAME)$(End)"
	@echo "$(Red)REMOVE CUB3D\033[3C->\033[5C$(BONUS)$(End)"

re : fclean all

.PHONY : all clean fclean re
