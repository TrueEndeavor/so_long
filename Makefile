# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2023/11/30 12:03:17 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTNAME = libft.a

CC = cc
CCFLAGS = -g -g3 -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

MLX       =	minilibx-linux/Makefile.gen
MLX_FLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR = ./include/libft_combined

INCLUDES = -I./include -I$(LIBFT_DIR)/include -I./minilibx-linux

SRCS			=	01src/so_long.c	\
					02mapvalidation/check_args.c	\
					02mapvalidation/check_ber.c	\
					02mapvalidation/validate_map.c \
					02mapvalidation/map_validation_utility_1.c \
					02mapvalidation/map_validation_utility_2.c \
					03structureinitialization/init_struct.c \
					display/display.c	\
					display/draw.c	\
					display/keyboard.c	\
					display/moveplayer.c	\
					display/printtexture.c	\
					parsing/checkmap.c	\
					parsing/parsing.c	\
					parsing/stockmap.c	\
					utils/error_handling.c \
					utils/freeandexit.c \
					utils/gnl_recursive.c
					
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME)
	$(CC) $(CCFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${NAME} $(MLX_FLAGS)

$(LIBFT_DIR)/$(LIBFTNAME):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@ 

all: $(MLX) $(NAME)

clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean
	${make}

test: ${NAME}
	./${NAME}

vtest: ${NAME}
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME}

.PHONY: all clean fclean re test vtest