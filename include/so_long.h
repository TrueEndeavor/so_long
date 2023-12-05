/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:14 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/05 16:09:23 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* *****************************   INCLUDES   ******************************* */
/* For function open() */
# include <fcntl.h>

/* close(), read(), write()  */
# include <unistd.h>

/* malloc(), free(), exit() */
# include <stdlib.h>

/* errno */
# include <errno.h>

/* Libft functions */
# include "libft.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

#include <stdio.h>

/* *****************************   STRUCTURES   *******************************/
typedef struct s_game_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background_ptr;
	void	*mini_background_ptr;
	void	*wall_ptr;
	void	*player_right_ptr;
	void	*player_left_ptr;
	void	*player_up_ptr;
	void	*player_down_ptr;
	void	*flower_ptr;
	void	*lover_ptr;
	int		height;
	int		width;
	t_list	*map;
	int		cat_x;
	int		cat_y;
	int		c_count;
	int		collected;
	int		e_count;
	int		p_count;
	int		moves;
	char	**dup_map;
	int		start_x;
	int		start_y;
}	t_game_data;

/* *****************************   CONSTANTS   ********************************/

# define PIXELS 64
# define MAX_HEIGHT 15
# define MAX_WIDTH 30
# define MIN_HEIGHT 3
# define MIN_WIDTH 3

int		check_args(int ac);

int		showerror(char *str);
int		display_error(char *str);

int		check_ber_extension(char *file_name);
int	destroy(t_game_data *game_data);
int	load_map(t_game_data *game_data, char *line);
int	validate_map(t_game_data *game_data);
int		check_rectangle(t_game_data *game_data);
int		check_size(t_game_data *game_data);
int		check_chars(t_game_data *game_data);
int		check_walls(t_game_data *game_data);
int		e_p_c_count(t_game_data *game_data);
int	check_valid_path(t_game_data *game_data);
int		set_dup_map(t_game_data *game_data);
int		flood_fill(int x, int y, t_game_data *game_data);
int		check_flood_fill(t_game_data *game_data);
int	set_up(t_game_data *game_data);
void	win_game(t_game_data *game_data, char move);
void	win_left(t_game_data *game_data);
void	win_right(t_game_data *game_data);
void	win_up(t_game_data *game_data);
void	win_down(t_game_data *game_data);

void read_and_initialize_map(t_game_data *game_data, char *file_name);
int		on_keypress(int keysym, t_game_data *data);
void	move_left(t_game_data *data);
void	move_right(t_game_data *data);
void	move_up(t_game_data *data);
void	move_down(t_game_data *data);
void	free_maps(t_game_data *game_data);
void	destroy_images(t_game_data *game_data);
int		check_arg(char *str);
void	set_size_get_line(t_game_data *game_data, char *map);
void	init_images(t_game_data *game_data);
void	set_images(t_game_data *game_data);
void	set_player(t_game_data *game_data);
int		on_keypress(int keysym, t_game_data *game_data);
void	move_left(t_game_data *game_data);
void	move_right(t_game_data *game_data);
void	move_up(t_game_data *game_data);
void	move_down(t_game_data *game_data);
char	check_next_move(t_game_data *game_data, int x, int y);
void	check_collected(t_game_data *game_data, int x, int y);
#endif

