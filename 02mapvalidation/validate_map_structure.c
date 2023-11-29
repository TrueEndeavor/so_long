/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:27 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/29 18:37:45 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_structure(char *file_name)
{
	int		fd;
	char	*line;
	int		eof;
	int		p_count;
	int		e_count;
	int		c_count;    
    size_t first_line_len = 0;
    size_t current_line_len;	

	p_count = 0;
	e_count = 0;
	c_count = 0;
	fd = open(file_name, O_RDONLY);
	eof = get_next_line(fd, &line);
    if (check_surrounded(line))
		exit (1);
    first_line_len = ft_strlen(line);
	while ((eof = get_next_line(fd, &line)) <= 1)
	{
		if (eof == 1)
		{
			if (check_surrounded(line))
				exit (1);
			break ;
		}
		current_line_len = strlen(line);
        if (current_line_len != first_line_len)
        {
            display_error("Map is not rectangular.");
            exit (1);
        }
		check_line_validity(line, &p_count, &e_count, &c_count);
		free(line);
	}
	if (p_count > 1)
	{
		display_error("More players found.");
		exit (1);
	}
	if (e_count > 1)
	{
		display_error("More exits found.");
		exit (1);
	}	
	if (p_count < 1)
	{
		display_error("There must be atleast one player.");
		exit (1);
	}	
	if (e_count < 1)
	{
		display_error("There must be atleast one exit.");
		exit (1);
	}	
	if (c_count < 1)
	{
		display_error("There must be atleast one collectible.");
		exit (1);
	}	
	return (0);
}




