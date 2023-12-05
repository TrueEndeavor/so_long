# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2023/12/05 15:04:09 by lannur-s         ###   ########.fr        #
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

SRCS			=	01src/so_long.c	\
					02inputvalidation/check_args.c	\
					02inputvalidation/check_ber.c	\
					03structureinitialization/load_map.c \
					03structureinitialization/moves.c \
					03structureinitialization/read_and_initialize_map.c \
					03structureinitialization/setup.c \
					03structureinitialization/win.c \
					04mapvalidation/validate_map.c \
					04mapvalidation/path.c \
					04mapvalidation/map_validation_utility_1.c \
					utils/error_handling.c \
					06destroy/destroy.c
					
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