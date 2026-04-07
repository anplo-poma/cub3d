CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g
NAME    = cub3D

#=== directories ===#

SRCS_DIR    = srcs
INCL_DIR    = include
MLX_DIR     = minilibx-linux
##------- ONLY for linna test on her own pc ---------
# MLX_DIR = minilibx-mac-osx
LIBFT_DIR   = libft
GNL_DIR     = get_next_line
PRINTF_DIR  = ft_printf

#=== libraries ===#

MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
##------- ONLY for linna test on her own pc ---------
## MLX_FLAGS   = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

#=== sources ===#

SRCS        = $(SRCS_DIR)/main.c \
              $(SRCS_DIR)/init.c \
              $(SRCS_DIR)/hook.c \
              $(SRCS_DIR)/render/render.c \
              $(SRCS_DIR)/render/find_wall.c \
			  $(SRCS_DIR)/render/find_wall_tools.c \
			  $(SRCS_DIR)/render/find_player.c \
			  $(SRCS_DIR)/render/texture.c \
              $(SRCS_DIR)/player_move.c \
              $(SRCS_DIR)/exit/error.c \
              $(SRCS_DIR)/exit/free.c \
              $(SRCS_DIR)/parsing/check_cub_file.c \
              $(SRCS_DIR)/parsing/check_map.c \
			  $(SRCS_DIR)/parsing/validate_map.c \
              $(SRCS_DIR)/parsing/parsing_toolbox.c \
			  $(SRCS_DIR)/parsing/parsing_toolbox2.c \
              $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I$(INCL_DIR) -I$(MLX_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

#=== rules ===#

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re