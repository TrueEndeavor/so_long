/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:20 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/04 12:49:22 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_game_data *game_data, char *line)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = ft_strdup(line);
	if (!new->content)
		return (0);
	new->next = NULL;
	if (!game_data->map)
	{
		game_data->map = new;
		return (1);
	}
	last = ft_lstlast(game_data->map);
	last->next = new;
	return (1);
}
