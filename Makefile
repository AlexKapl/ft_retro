# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:34:18 by akaplyar          #+#    #+#              #
#    Updated: 2017/11/05 22:55:49 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @clang++
CFLAGS = -Wall -Wextra -Werror

HEADER = ft_retro.h

OBJ = main.o Player.o AObject.o Field.o List.o StarObject.o\
	  ObjectSpawner.o Asteroid.o Enemy.o Bullet.o PowerUp.o

NAME = ft_retro

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) -I $(HEADER) $(OBJ) -lncurses
	@printf "\x1B[32m\0%s created\x1B[0m\0\n" $(NAME)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\x1B[32m\0Compile %s\x1B[0m\0\n" $<

clean:
	@rm -rf $(OBJ)
	@printf "\x1B[31m\0%s objects cleared\x1B[0m\0\n" ${NAME}

fclean: clean
	@rm -rf $(NAME)
	@printf "\x1B[31m\0%s deleted\x1B[0m\0\n" ${NAME}

re: fclean all
