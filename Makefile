# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:39:49 by doduwole          #+#    #+#              #
#    Updated: 2023/09/01 13:17:27 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	$(wildcard main.c src/*.c src/*/*.c src/*/*/*.c src/*/*/*/*.c)

RM = rm -rf
CFLAGS = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

CC = gcc -g -fsanitize=address 

LIBFTDIR = ./inc/libft/

LIBFTA = ./inc/libft/libft.a

MLX_DIR = ./mlx/

MLX = ./mlx/libmlx.a

LINK = -Lmlx -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

%.o: %.c $(LIBFTA)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(LIBFTA) $(MLX) $(SRC) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(MLX):
	@make -C $(MLX_DIR)
	@make clean -C $(MLX_DIR)

$(LIBFTA):
	@make all -C $(LIBFTDIR)
	@make clean -C $(LIBFTDIR)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@$(RM) $(OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
