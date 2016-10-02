# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <telain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 17:19:39 by telain            #+#    #+#              #
#    Updated: 2016/09/18 15:18:00 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
PATH_SRC = src/

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

SRC =  main.c\
	  data_init.c\
	  display.c\
	  pixel_put.c\
	  draw_window.c\
	  inputs.c\
	  raycast.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@printf "Compiling $(NAME) ...\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@printf "$(NAME) compiled\n"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $^
	@printf "[\e[32m$(NAME) object\e[0m]\e[32m--\e[0m--\e[32m--\e[0m>"
	@printf "\t: [\e[32m✓\e[0m] : $@"
	@printf "\e[0m\n"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
