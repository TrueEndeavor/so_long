/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/05 16:16:54 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_game_data *data)
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
			if (((char *)current->content)[x] == 'P')
			{
				data->cat_x = x;
				data->cat_y = y;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->player_right_ptr, data->cat_x * PIXELS,
					data->cat_y * PIXELS);
			}
			x++;
		}
		y++;
		current = current->next;
	}
}

void	init_images(t_game_data *data)
{
	data->background_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/floor.xpm", &(data->width), &(data->height));
	data->mini_background_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/floor.xpm", &(data->width), &(data->height));
	data->flower_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/collectible.xpm", &(data->width), &(data->height));
	data->lover_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/lover_4.xpm", &(data->width), &(data->height));
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/wall.xpm", &(data->width), &(data->height));
	data->player_left_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player.xpm", &(data->width), &(data->height));
	data->player_right_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player.xpm", &(data->width), &(data->height));
	data->player_up_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player.xpm", &(data->width), &(data->height));
	data->player_down_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player.xpm", &(data->width), &(data->height));
	if (!data->background_ptr || !data->mini_background_ptr || !data->flower_ptr
		|| !data->lover_ptr || !data->wall_ptr || !data->player_left_ptr
		|| !data->player_right_ptr || !data->player_up_ptr || !data->player_down_ptr)
	{
		ft_printf("Error\nImage not loaded");
		destroy(data);
	}
}


void	set_images(t_game_data *data)
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
			if (((char *)current->content)[x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall_ptr, x * PIXELS, y * PIXELS);
			if (((char *)current->content)[x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->flower_ptr, x * PIXELS, y * PIXELS);
			if (((char *)current->content)[x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->lover_ptr, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
		current = current->next;
	}
}

int	set_up(t_game_data *game_data)
{
	game_data->win_ptr = mlx_new_window(game_data->mlx_ptr, game_data->width * PIXELS,
			game_data->height * PIXELS, "Purr-fect Petals Pursuit");
	if (!game_data->win_ptr)
	{
		ft_printf("Error\nCannot open window\n");
		destroy(game_data);
		return (0);
	}
	init_images(game_data);
	dprintf(1, "coucou\n");
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
		game_data->background_ptr, 0, 0);
	set_images(game_data);
	set_player(game_data);
	game_data->moves = 0;
	game_data->collected = 0;
	
	return (1);
}
