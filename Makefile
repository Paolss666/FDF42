# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 16:15:47 by npaolett          #+#    #+#              #
#    Updated: 2023/08/07 14:10:27 by npaolett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus
CC = cc

RM = rm -fr

CFLAGS = -g3 -Wall -Wextra -Werror 
MLXFLAGS = -lX11 -lXext -lm
INCL = -I -I./libft -I./mlx_linux

SRC = 	src/fdf.c\
		src/create_matrix.c\
		src/data_init.c\
		src/draw_map.c\
		src/bresnham.c\
		src/ft_atoi_hex.c\
		src/isometric.c\
		src/key_window.c\
		src/print_error.c\
		src/read_map.c\
		src/stack.c \


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
#	cc -o $(NAME) $(OBJ)

LIBFT = ./libft/libft.a
LIBMLX = ./mlx_linux/libmlx_Linux.a

$(NAME): $(OBJ)
	make lib
	make mlx
	cc -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

$(BONUS): $(OBJ_BONUS)
	make lib
	make mlx
	cc -o $(BONUS) $(OBJ_BONUS) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

all : $(NAME)

bonus : $(BONUS)

%.o: %.c
	cc $(INCL) $(CFLAGS) -o $@ -c $<

mlx:
	make -C ./mlx_linux/ all

lib:
	make -C ./libft/ all
	
clean:
	@make -C libft/ clean
	@make -C mlx_linux/ clean
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX) $(BONUS)

re: fclean 
	make all

rebonus: fclean
		make bonus 

.PHONY: all clean fclean re