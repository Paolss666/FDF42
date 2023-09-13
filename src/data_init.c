/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:00:54 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/02 17:53:13 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

t_point	*point_init(int x, int y, t_fdf *fdf)
{
	t_point	*p;

	if (x < 0 || x >= fdf->width || y < 0 || y >= fdf->height)
		return (NULL);
	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = fdf->matrix[y][x].z.altitude * fdf->altitude;
	return (p);
}
