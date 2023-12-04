/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utility_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/04 16:48:04 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_game_data *game_data)
{
	t_list	*current;

	current = game_data->map;
	while (current)
	{
	dprintf(1, "(char *)current->content %s\n", (char *)current->content);
	dprintf(1, "ft_strlen((char *)current->content) %zu\n", ft_strlen((char *)current->content));
	dprintf(1, "(size_t) game_data->width %zu\n", (size_t) game_data->width);	
		if ((ft_strlen((char *)current->content)) != (size_t) game_data->width)
		{
			ft_printf("Error\nMap not rectangle\n");
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_size(t_game_data *game_data)
{
	if (game_data->height < MIN_HEIGHT || game_data->width < MIN_WIDTH
		|| game_data->width > MAX_WIDTH || game_data->height > MAX_HEIGHT)
	{
		ft_printf("Error\nSize not adapted for game\n");
		return (0);
	}
	return (1);
}

int	e_p_c_count(t_game_data *game_data)
{
	t_list	*current;
	int		x;
	int		y;

	current = game_data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char*)current->content)[x])
		{
			if (((char*)current->content)[x] == 'C')
				game_data->c_count++;
			if (((char*)current->content)[x] == 'E')
				game_data->e_count++;
			if (((char*)current->content)[x] == 'P')
				game_data->p_count++;
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}

int	check_chars(t_game_data *game_data)
{
	t_list	*current;
	int		x;
	int		y;

	current = game_data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char *)current->content)[x] != '\0' && x < game_data-> width)
		{
		dprintf(1, "((char *)current->content)[%d] =%c\n", x, ((char *)current->content)[x]);
			if (((char *)current->content)[x] != '0' 
				&& ((char *)current->content)[x] != '1'
				&& ((char *)current->content)[x] != 'C' 
				&& ((char *)current->content)[x] != 'E'
				&& ((char *)current->content)[x] != 'P')
			{
				ft_printf("Error\nInvalid char in map\n");
				return (0);
			}
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}

int	check_walls(t_game_data *game_data)
{
	t_list	*current;
	int		x;
	int		y;

	current = game_data->map;
	y = 0;
	while (current)
	{
		if (y == 0 || y == (game_data->height - 1))
		{
			x = 0;
			while (((char *)current->content)[x] != '\0' && x < game_data-> width)
			{
				if (((char *)current->content)[x] != '1')
					return (0);
				x++;
			}
		}
		if (((char *)current->content)[0] != '1'
			|| ((char *)current->content)[game_data->width - 1] != '1')
			return (0);
		current = current->next;
		y++;
	}
	return (1);
}

char	check_next_move(t_game_data *game_data, int x, int y)
{
	t_list	*current;
	int		i;

	current = game_data->map;
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

void	check_collected(t_game_data *game_data, int x, int y)
{
	if (game_data->dup_map[y][x] != 'D')
	{
		game_data->dup_map[y][x] = 'D';
		game_data->collected++;
	}
}