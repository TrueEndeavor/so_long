/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:00:50 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/28 12:45:00 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] == '.'
		&& file_name[len - 3] == 'b'
		&& file_name[len - 2] == 'e'
		&& file_name[len - 1] == 'r')
	{
		if (access(file_name, R_OK) == -1)
		{
			display_error(strerror(errno));
		}
		return (0);
	}
	display_error("[ERROR] Files without .ber extension not accepted. "\
	"Define your map description in a file ending with the .ber "\
	"extension.");
	return (1);
}

int	get_x_and_y(t_long *sl, char *filename)
{
	char	*line;
	int		fd;    
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	sl->oldx = ft_strlen(line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		sl->x = ft_strlen(line);
		if (sl->x != sl->oldx)
			showerror(sl, "Map is not rectangular");
		sl->oldx = sl->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		sl->y++;
	}
	if (sl->y == 0 || sl->x == 0)
		showerror(sl, "Map is not correct or not well formated");
	sl->yscreen = sl->y * 64;
	free(line);
	sl->xscreen = sl->x * 64;
	close(fd);
	return (0);
}