/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:10:30 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/03 14:41:49 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int	close_win(t_fdf *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_display(param->mlx_ptr);
	free(param->mlx_ptr);
	free(param);
	exit(0);
}

int	esc_close(int key, t_fdf *param)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(param->mlx_ptr, param->img_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_display(param->mlx_ptr);
		free(param->mlx_ptr);
		free(param);
		exit(0);
	}
	return (0);
}
