NAME = cub3D

CC = gcc
FLAGS = -Wall -Werror -Wextra -g
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER) -I$(MLX_HEADER)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADER = $(LIBFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx/
MLX_HEADER = $(MLX_DIR)

HEADER_DIR = ./includes/
HEADER =  $(addprefix $(HEADER_DIR), cub3D.h)

G = game_algs/
P = parser/
SRC_DIR = ./sources/
SRC_LIST = main.c \
		   $PparseMap.c \
		   $Plst.c\
		   $PparseTextures.c \
		   $Pparse.c \
		   $PvalidMap.c \
		   $Gexit_game.c \
		   $Ggame_start.c \
		   $Ggraphics.c \
		   $Ginput.c

SRC = $(SRC_DIR)$(SRC_LIST)

O = ./objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(O), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(O) $(OBJ)
	@$(CC) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME) $(FLAGS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(O):
	@[ -d $(O) ] || mkdir -p $(O)
	@[ -d $(O)$(P) ] || mkdir -p $(O)$(P)
	@[ -d $(O)$(G) ] || mkdir -p $(O)$(G)


$(O)%.o : $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@echo "$(NAME): $(GREEN)Creating $(MLX)...$(RESET)"
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean
	@rm -rf $(O)
	@echo "$(NAME): $(RED)$(O) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

norm:
	@$(MAKE) -sC $(LIBFT_DIR) norm
	@norminette $(SRC_DIR)*.c $(HEADER_DIR)*.h

fclean: clean
	@rm -f $(MLX)
	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

gc:
	@$(MAKE) fclean
	@git add .
	@git commit -m "fast commit"
	@echo "$(GREEN)commit was commited$(RESET)"

gp:
	@$(MAKE) gc
	@git push
	@echo "$(GREEN)fast commit was pushed$(RESET)"