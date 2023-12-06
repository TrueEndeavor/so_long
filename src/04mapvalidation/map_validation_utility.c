/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utility.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/06 18:47:46 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_data *data)
{
	t_list	*current;

	current = data->map;
	while (current)
	{
		if ((ft_strlen((char *)current->content)) != (size_t) data->width)
		{
			display_error("Map is not rectangular");
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_size(t_data *data)
{
	if (data->height < MIN_HEIGHT || data->width < MIN_WIDTH
		|| data->width > MAX_WIDTH || data->height > MAX_HEIGHT)
	{
		display_error("Size not adapted for game");
		return (0);
	}
	return (1);
}

int	e_p_c_count(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char *)current->content)[x])
		{
			if (((char *)current->content)[x] == 'C')
				data->c_count++;
			if (((char *)current->content)[x] == 'E')
				data->e_count++;
			if (((char *)current->content)[x] == 'P')
				data->p_count++;
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}

int	check_chars(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char *)current->content)[x] != '\0' && x < data-> width)
		{
			if (((char *)current->content)[x] != '0'\
				&& ((char *)current->content)[x] != '1'\
				&& ((char *)current->content)[x] != 'C'\
				&& ((char *)current->content)[x] != 'E'\
				&& ((char *)current->content)[x] != 'P')
			{
				display_error("Invalid char in map");
				return (0);
			}
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}

int	check_walls(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		if (y == 0 || y == (data->height - 1))
		{
			x = 0;
			while (((char *)current->content)[x] != '\0' && x < data-> width)
			{
				if (((char *)current->content)[x] != '1')
					return (0);
				x++;
			}
		}
		if (((char *)current->content)[0] != '1'
			|| ((char *)current->content)[data->width - 1] != '1')
			return (0);
		current = current->next;
		y++;
	}
	return (1);
}

char	check_next_move(t_data *data, int x, int y)
{
	t_list	*current;
	int		i;

	current = data->map;
	i = 0;
	while (i < y && current)
	{
		current = current->next;
		i++;
	}
	if (((char *)current->content)[x] == '1')
		return ('1');
	if (((char *)current->content)[x] == 'C')
		return ('C');
	if (((char *)current->content)[x] == 'E')
		return ('E');
	if (((char *)current->content)[x] == '0')
		return ('0');
	return ('0');
}

void	check_collected(t_data *data, int x, int y)
{
	if (data->dup_map[y][x] != 'D')
	{
		data->dup_map[y][x] = 'D';
		data->collected++;
	}
}
