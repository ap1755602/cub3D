# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodney <frodney@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 22:48:00 by frodney           #+#    #+#              #
#    Updated: 2021/08/02 14:38:12 by frodney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -O3 -c
INCLUDES = -I$(HEADER_DIR)
HEADER_DIR = ./includes/
HEADER = $(HEADER_DIR)/libft.h
SRC_DIR = ./sources/
SRC_LIST = ft_memset.c	ft_bzero.c	ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strncmp.c  ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_itoa.c ft_substr.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c ft_strmapi.c \
		ft_strtrim.c ft_split.c get_next_line.c ft_strndup.c \
		terminate.c ft_lst_add_back.c gnl_utils.c ft_isnum.c\

SRC = $(SRC_DIR)/$(SRC_LIST)
OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

norm:
	norminette $(SRC_DIR)*.c $(HEADER_DIR)*.h

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
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