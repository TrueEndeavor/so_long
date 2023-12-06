/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/06 18:45:53 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_data *data)
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
					data->player_ptr, data->cat_x * PIXELS,
					data->cat_y * PIXELS);
			}
			x++;
		}
		y++;
		current = current->next;
	}
}

void	init_images(t_data *data)
{
	data->background_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/empty.xpm", &(data->width), &(data->height));
	data->mini_background_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/paw.xpm", &(data->width), &(data->height));
	data->flower_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/collectible.xpm", &(data->width), &(data->height));
	data->lover_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/exit_3.xpm", &(data->width), &(data->height));
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/wall.xpm", &(data->width), &(data->height));
	data->player_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player.xpm", &(data->width), &(data->height));
	if (!data->background_ptr || !data->mini_background_ptr || !data->flower_ptr
		|| !data->lover_ptr || !data->wall_ptr || !data->player_ptr)
	{
		display_error("Image not loaded");
		on_destroy(data);
	}
}


void	set_images(t_data *data)
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
			if (((char *)current->content)[x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->background_ptr, x * PIXELS, y * PIXELS);
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

int	set_up(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->width * PIXELS, data->height * PIXELS, \
		":)       Purr-fect Petals Pursuit       :)");
	if (!data->win_ptr)
	{
		display_error("Cannot open window");
		on_destroy(data);
		return (0);
	}
	init_images(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_ptr, data->width * PIXELS, data->height * PIXELS);
	set_images(data);
	set_player(data);
	data->moves = 0;
	data->collected = 0;
	return (1);
}
