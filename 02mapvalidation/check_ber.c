/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:00:50 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/29 19:10:02 by lannur-s         ###   ########.fr       */
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
	else
	{
		display_error("[ERROR] Files without .ber extension not accepted. "\
		"Define your map description in a file ending with the .ber "\
		"extension.");
	}
	return (1);
}
