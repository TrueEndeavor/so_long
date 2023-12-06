# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2023/12/06 19:06:14 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTNAME = libft.a

CC = cc
CCFLAGS = -g -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

MLX       =	minilibx-linux/Makefile.gen
MLX_FLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR = ./include/libft_combined

INCLUDES = -I./include -I$(LIBFT_DIR)/include -I./minilibx-linux

SRCS			=	src/01main/so_long.c	\
					src/02inputvalidation/check_args.c	\
					src/02inputvalidation/check_ber.c	\
					src/03structureinitialization/load_map.c \
					src/03structureinitialization/read_and_initialize_map.c \
					src/03structureinitialization/setup.c \
					src/04mapvalidation/validate_map.c \
					src/04mapvalidation/path.c \
					src/04mapvalidation/map_validation_utility.c \
					src/05moves/cat_movement.c \
					src/05moves/winning_actions.c \
					src/06destroy/destroy.c \
					src/07error/error_handling.c
					
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(OBJS)
	$(CC) $(CCFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${NAME} $(MLX_FLAGS)

$(LIBFT_DIR)/$(LIBFTNAME):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@ 

all: $(NAME) $(MLX)

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