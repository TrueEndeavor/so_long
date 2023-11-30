/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stockmap(t_game_data *game_data,char *filename)
{
	char	*line;
	int		fd;
	int		ret;
	int		nb;

	nb = 0;
	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		stockline(game_data,line, nb);
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		nb++;
	}
	free(line);
	return (0);
}

int	stockline(t_game_data *game_data,char *line, int nb)
{
	int	index;

	index = 0;
	while (line[index])
	{
		game_data->casetotal++;
		game_data->map[nb][index] = replacechar(line[index]);
		if (line[index] == 'P')
		{
			game_data->playerset++;
			game_data->player_x = index;
			game_data->player_y = nb;
		}
		if (line[index] == 'E')
			game_data->exitset++;
		if (line[index] == 'C')
			game_data->collectibletotal++;
		if (line[index] != 'P' && line[index] != 'E' && line[index]
			!= 'C' && line[index] != '1' && line[index] != '0')
			showerror(game_data,"Wrong character in map");
		index++;
	}
	return (0);
}

int	checkmap(t_game_data *game_data)
{
	if (game_data->playerset < 1)
		showerror(game_data,"You must set a player 'P'");
	if (game_data->playerset > 1)
		showerror(game_data,"Multiplayer mode unavailable");
	if (game_data->exitset < 1)
		showerror(game_data,"You must set an exit 'E'");
	if (game_data->exitset > 1)
		showerror(game_data,"Only 1 exit is permitted");
	if (game_data->collectibletotal == 0)
		showerror(game_data,"You must set a collectible 'C'");
	checkthewall(game_data);
	return (0);
}


int	checkifgood(char c)
{
	if (c != '0' && c != 'a' && c != '1' && c != 'P' && c != 'c' && c != 'E'
		&& c != 'd' && c != 'C' && c != 'e')
		return (0);
	return (1);
}
