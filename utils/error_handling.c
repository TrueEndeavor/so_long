/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:33:13 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/28 11:37:53 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	showerror(t_long *sl, char *str)
{
	write(1, "Error:", 6);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	freeandexit(sl);
	return (0);
}

int	display_error(char *str)
{
	write(1, "Error:", 6);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	return (0);
}
