/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:00:50 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/18 09:49:55 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'b'\
		|| file_name[len - 2] != 'e' || file_name[len - 1] != 'r')
	{
		display_error("Invalid file name. \
		Files without .ber extension not accepted.");
		return (0);
	}
	return (1);
}
