# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simzam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/10 09:17:10 by simzam            #+#    #+#              #
#    Updated: 2016/07/05 11:25:12 by simzam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = rtv1

FLAG = -Wall -Wextra -g

SRC = src/init_stuff.c src/intersections.c src/iomanips.c src/lighting.c \
	  src/rtv1.c utils/ft_clamp.c utils/ft_vec.c utils/ft_vec2.c utils/ft_vec3.c src/ray_tracer.c

RM = rm -f

MACMLX = -lm -lmlx -framework OpenGL -framework AppKit
LIXMLX = -lm -lmlx -lXext -lX11

INC = -I /usr/include/X11 -I includes/

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re


all: $(NAME)

%.o: %.c
	@echo "Compilied\t\033[33m$@\033[0m"
	@$(CC) $(FLAG) -c -o $@ $^ $(INC)

$(NAME): $(OBJ)
		@echo "Linking objects with the libraries..."
ifeq ($(CC), cc)
		@$(CC) $(FLAG) $(OBJ) -o $@ $(INC) $(MACMLX)
else
		@$(CC) $(FLAG) $(OBJ) -o $@ $(INC) $(MACMLX)
endif
		@echo "\033[32mDone!\033[0m\nManufactured\t\033[31m$@\033[0m..."

clean:
		@echo "Cleaning\t\033[34m$(NAME)\033[m"
		@$(RM) $(OBJ)
		@cd utils/ && rm -f
		@cd src/ && rm -f
		@echo "**********Done!********"

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
