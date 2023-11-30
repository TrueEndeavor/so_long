/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:20 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:35:57 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_struct(t_game_data *game_data)
{
	game_data->keyboard[BACK] = 0;
	game_data->keyboard[RED_BUTTON] = 0;
	game_data->keyboard[ESC] = 0;
	game_data->keyboard[LEFT] = 0;
	game_data->keyboard[RIGHT] = 0;
	game_data->keyboard[ADVANCE] = 0;
	game_data->bpp = 0;
	game_data->casein = 0;
	game_data->casetotal = 0;
	game_data->y = 0;
	game_data->x = 0;
	game_data->collectible = 0;
	game_data->collectibletotal = 0;
	game_data->s_line = 0;
	game_data->maptofree = -1;
	game_data->move = 0;
	game_data->playerset = 0;
	game_data->collectibleset = 0;
	game_data->exitset = 0;
	game_data->lastplayer_x = -1;
	game_data->lastplayer_y = -1;
	game_data->mlx_ptr = NULL;
	return (0);
}

/* int	extract_map_dimensions(t_game_data *game_data, const char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	game_data->map_width = ft_strlen(line);
	game_data->map_height = 1;
	game_data->prev_width = game_data->map_width;
	free(line);

	while (get_next_line(fd, &line) > 0)
	{
		game_data->map_width = ft_strlen(line);
		if (game_data->map_width != game_data->prev_width)
		{
			game_data->map_width = game_data->prev_width;
			break ;
		}
		game_data->prev_width = game_data->map_width;
		game_data->map_height++;
		free(line);
	}
	game_data->screen_height = game_data->map_height * TILE_SIZE;
	game_data->screen_width = game_data->map_width * TILE_SIZE;
	close(fd);
	return 0;
} */


int	mallocmap(t_game_data *game_data)
{
	int	i;

	i = 0;
	game_data->map = malloc(sizeof(char *) * game_data->y);
	while (i < game_data->y)
	{
		game_data->map[i] = malloc(sizeof(char) * (game_data->x + 1));
		i++;
	}
	game_data->maptofree = 1;
	return (1);
}