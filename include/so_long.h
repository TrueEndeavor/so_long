/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:14 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:38:10 by lannur-s         ###   ########.fr       */
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

# include "mlx.h"
#include <stdio.h>

/* *****************************   STRUCTURES   *******************************/
typedef struct s_game_data
{
	char			**map;
	int				xscreen;
	int				yscreen;

	int				x;
	int				y;
	int				oldx;
	int				collectibleparse;
	int				exitparse;
	int				player_x;
	int				player_y;
	int				lastplayer_x;
	int				lastplayer_y;
	int				collectible;
	int				collectibletotal;
	int				move;
	int				playerset;
	int				exitset;
	int				collectibleset;

	char			*pxl;
	int				bpp;
	int				s_line;
	double			casetotal;
	double			casein;
	int				ed;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				keyboard[70000];
	int				maptofree;

	int				bpp_text[10];
	int				sline_text[10];
	int				ed_text[10];
	char			*ptr_text[10];
	void			*text[10];
	int				widthtext[10];
	int				heighttext[10];
	int				actualtext;
	unsigned int	color;
}	t_game_data;


/* *****************************   CONSTANTS   ********************************/


# if defined(__APPLE__) && defined(__MACH__)
#  define ADVANCE 13
#  define BACK 1
#  define RIGHT 2
#  define LEFT 0
#  define ESC 53
#  define RED_BUTTON 79
#  define CLOSERED 17
# else
#  define ADVANCE 119
#  define BACK 115
#  define RIGHT 100
#  define LEFT 97
#  define ESC 65307
#  define RED_BUTTON 79
#  define CLOSERED 33
# endif


int		check_args(int ac);

int		get_next_line(int fd, char **out);
int		showerror(t_game_data *game_data,char *str);
int		display_error(char *str);
int		check_ber_extension(char *file_name);
int	validate_map(char *file_name, size_t *length, size_t *height);
int		check_surrounded(char *line);
int		check_sidewalls(char *line);
int		check_valid_character(char *line);
int		count_char(char *line, char c);
int		check_line_validity(char *line, int *p_count, int *e_count, int *c_count);
int		init_struct(t_game_data *game_data);
int	is_map_not_surrounded(char *line);
int	is_map_not_rectangular(char *line, size_t prev_length);
int	check_counts(int p_count, int e_count, int c_count);

int		get_x_and_y(t_game_data *game_data,char *argv);
int		visible(t_game_data *game_data);
char	*ft_strcpy(char *dest, char *src);
int		parsing(t_game_data *game_data,char *argv);
int		stockmap(t_game_data *game_data,char *argv);
int		mallocmap(t_game_data *game_data);
int		render_calcul(t_game_data *game_data);
int		render(t_game_data *game_data);
void	floodandfill2(t_game_data *game_data,int mapy, int mapx);
int		checkmap(t_game_data *game_data);
int		numberblank(char *str);
int		get_next_line(int fd, char **line);
int		printtexture(t_game_data *game_data,int starter_X, int starter_Y);
int		pos_player(t_game_data *game_data);
int		initplayer(t_game_data *game_data);
int		loadtexture(t_game_data *game_data);
int		loadtexture3(t_game_data *game_data);
int		gettextnum(int X, int Y, t_game_data *game_data);
int		moveplayer(int nb, t_game_data *game_data);
int		checkaremove(t_game_data *game_data);
int		stockline(t_game_data *game_data,char *line, int nb);
int		checkifgood(char c);
char	replacechar(char c);
int		checkthewall(t_game_data *game_data);
int		floodandfill(t_game_data *game_data,int mapy, int mapx);
int		displaymove(t_game_data *game_data,int nb);
int		freemap(t_game_data *game_data);
void	resetkeyboard(t_game_data *game_data);
int		checkaround(int mapx, int mapy, t_game_data *game_data);
int		ft_key_hit(int keycode, t_game_data *game_data);
int		ft_key_release(int keycode, t_game_data *game_data);
int		ft_keyboard(t_game_data *display);
int		closebyredbutton(t_game_data *game_data);
int		freeandexit(t_game_data *game_data);
int		display(t_game_data *game_data);
int		go_hooking(t_game_data *game_data);
int		createwindow(t_game_data *game_data);
int		key_loop(t_game_data *game_data);
int		put_pxl(t_game_data *game_data,int x, int y, unsigned int c);

#endif

