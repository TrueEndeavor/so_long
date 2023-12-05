/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_initialize_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/05 15:46:50 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_readable(t_game_data *game_data, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0 || read(fd, &line, 0) < 0)
	{
		display_error(strerror(errno));
		destroy(game_data);
	}
	return (fd);
}

char *trim_newline(char *str){
    int len = ft_strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return (str);
}

void	read_and_initialize_map(t_game_data *game_data, char *file_name)
{
	int		fd;
	char	*line;

	fd = check_readable(game_data, file_name);
	line = get_next_line(fd);
	game_data->width = (int) ft_strlen(line) - 1;
	if (!line)
	{
		display_error("[ERROR] Cannot read map");
		destroy(game_data);
	}
	while (line)
	{
		if (!line)
			destroy(game_data);
		game_data->height++;
		if (!load_map(game_data, trim_newline(line)))
			destroy(game_data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
