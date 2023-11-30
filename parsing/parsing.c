/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:30 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(t_game_data *game_data,char *argv)
{
	mallocmap(game_data);
	stockmap(game_data,argv);
	checkmap(game_data);
	return (0);
}
/* 
int	get_x_and_y(t_game_data *game_data,char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	game_data->oldx = ft_strlen(line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		game_data->x = ft_strlen(line);
		if (game_data->x != game_data->oldx)
			showerror(game_data,"Map is not rectangular");
		game_data->oldx = game_data->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		game_data->y++;
	}
	if (game_data->y == 0 || game_data->x == 0)
		showerror(game_data,"Map is not correct or not well formated");
	game_data->yscreen = game_data->y * 64;
	free(line);
	game_data->xscreen = game_data->x * 64;
	close(fd);
	return (0);
} */

char	replacechar(char c)
{
	if (c == '0')
		return ('a');
	if (c == '1')
		return ('1');
	if (c == 'P')
		return ('c');
	if (c == 'E')
		return ('d');
	if (c == 'C')
		return ('e');
	return (0);
}


