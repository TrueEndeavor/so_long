/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:17 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/06 19:01:23 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move(t_data *data, int new_cat_x, int new_cat_y, char direction)
{
    char next_move = check_next_move(data, new_cat_x, new_cat_y);

    if (next_move == '1')
        return;

    if (next_move == 'E' && data->collected == data->c_count)
        win_game(data, direction);

    if (next_move == 'E' && data->collected != data->c_count)
        return;

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
                             data->mini_background_ptr, data->cat_x * PIXELS,
                             data->cat_y * PIXELS);

    data->cat_x = new_cat_x;
    data->cat_y = new_cat_y;

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
                             data->player_ptr, data->cat_x * PIXELS,
                             data->cat_y * PIXELS);

    data->moves++;
    ft_printf("moves: %d\n", data->moves);

    if (next_move == 'C')
        check_collected(data, data->cat_x, data->cat_y);
}

void move_left(t_data *data)
{
    move(data, data->cat_x - 1, data->cat_y, 'l');
}

void move_right(t_data *data)
{
    move(data, data->cat_x + 1, data->cat_y, 'r');
}

void move_up(t_data *data)
{
    move(data, data->cat_x, data->cat_y - 1, 'u');
}

void move_down(t_data *data)
{
    move(data, data->cat_x, data->cat_y + 1, 'd');
}

int on_keypress(int keysym, t_data *data)
{
    (void)data;
    if (keysym == LEFT_ARROW || keysym == A_KEY)
        move_left(data);
    if (keysym == UP_ARROW || keysym == W_KEY)
        move_up(data);
    if (keysym == RIGHT_ARROW || keysym == D_KEY)
        move_right(data);
    if (keysym == DOWN_ARROW || keysym == S_KEY)
        move_down(data);
    if (keysym == 65307 || keysym == Q_KEY)
        on_destroy(data);
    return 0;
}
