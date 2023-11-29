/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:14 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/29 19:08:37 by lannur-s         ###   ########.fr       */
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
typedef struct s_long
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
}	t_long;


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


int		get_next_line(int fd, char **out);
int		showerror(t_long *sl, char *str);
int		display_error(char *str);
int		check_ber_extension(char *file_name);
int		validate_map_structure(char *file_name);
int		init_struct(t_long *sl);
int		check_surrounded(char *line);
int		check_sidewalls(char *line);
int		check_valid_character(char *line);
int		count_char(char *line, char c);
int		check_line_validity(char *line, int *p_count, int *e_count, int *c_count);

int		get_x_and_y(t_long *sl, char *argv);
int		visible(t_long *sl);
char	*ft_strcpy(char *dest, char *src);
int		parsing(t_long *sl, char *argv);
int		stockmap(t_long *sl, char *argv);
int		mallocmap(t_long *sl);
int		render_calcul(t_long *sl);
int		render(t_long *sl);
void	floodandfill2(t_long *sl, int mapy, int mapx);
int		checkmap(t_long *sl);
int		numberblank(char *str);
int		get_next_line(int fd, char **line);
int		printtexture(t_long *sl, int starter_X, int starter_Y);
int		pos_player(t_long *sl);
int		initplayer(t_long *sl);
int		loadtexture(t_long *sl);
int		loadtexture3(t_long *sl);
int		gettextnum(int X, int Y, t_long *sl);
int		moveplayer(int nb, t_long *sl);
int		checkaremove(t_long *sl);
int		stockline(t_long *sl, char *line, int nb);
int		checkifgood(char c);
char	replacechar(char c);
int		checkthewall(t_long *sl);
int		floodandfill(t_long *sl, int mapy, int mapx);
int		displaymove(t_long *sl, int nb);
int		freemap(t_long *sl);
void	resetkeyboard(t_long *sl);
int		checkaround(int mapx, int mapy, t_long *sl);
int		ft_key_hit(int keycode, t_long *sl);
int		ft_key_release(int keycode, t_long *sl);
int		ft_keyboard(t_long *display);
int		closebyredbutton(t_long *sl);
int		freeandexit(t_long *sl);
int		display(t_long *sl);
int		go_hooking(t_long *sl);
int		createwindow(t_long *sl);
int		key_loop(t_long *sl);
int		put_pxl(t_long *sl, int x, int y, unsigned int c);

#endif

