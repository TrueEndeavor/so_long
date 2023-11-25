# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2023/11/25 13:13:36 by lannur-s         ###   ########.fr        #
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

SRCS			=	so_long.c	\
					get_next_line.c \
					display/display.c	\
					display/draw.c	\
					display/keyboard.c	\
					display/moveplayer.c	\
					display/printtexture.c	\
					parsing/checkmap.c	\
					parsing/parsing.c	\
					parsing/stockmap.c	\
					utils/freeandexit.c
	
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

.PHONY: all clean fclean re
