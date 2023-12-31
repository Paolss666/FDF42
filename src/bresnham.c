/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:27:14 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/07 13:12:31 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int	compare(int a, int b)
{
	int	ret;

	ret = 0;
	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}
/*
le coordinate sono all'interno dei limiti dell'immagine, 
il colore viene assegnato al pixel corrispondente nell'immagine utilizzando
l'indirizzo di memoria calcolato. Questo processo consente di disegnare pixel
specifici sulla griglia immagine,
contribuendo così alla creazione di modelli tridimensionali.
*/

void	put_pixel(t_fdf *fdf, int x, int y)
{
	char	*addr;

	addr = NULL;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr, \
			&fdf->bpp, &fdf->size_line, &fdf->endian);
		addr = fdf->img_data + (y * fdf->size_line + x * (fdf->bpp / 8));
		*(unsigned int *)addr = fdf->color;
	}
}

t_param	*init_param(t_point *a, t_point *b)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->dx = abs(b->x - a->x);
	param->sx = compare(a->x, b->x);
	param->dy = -abs(b->y - a->y);
	param->sy = compare(a->y, b->y);
	param->err = param->dx + param->dy;
	return (param);
}
/*
Questi parametri includono la differenza in x (dx) e in y (dy) tra i punti,
oltre a variabili come
sx e sy che determinano la direzione in cui incrementare le coordinate x e y 
rispettivamente.
Se e2 è maggiore o uguale alla differenza in y (dy),
l'errore viene aggiornato e la coordinata x viene incrementata 
(decrementata se sx è negativo) per far avanzare la linea in orizzontale.
Se e2 è minore o uguale alla differenza in x (dx),
l'errore viene aggiornato e la coordinata y viene incrementata
(decrementata se sy è negativo) per far avanzare la linea in verticale.
*/

void	bresnham(t_fdf *fdf, t_point *a, t_point *b)
{
	t_param	*param;

	param = init_param(a, b);
	while (1)
	{
		put_pixel(fdf, a->x, a->y);
		if (a->x == b->x && a->y == b->y)
			break ;
		param->e2 = 2 * param->err;
		if (param->e2 >= param->dy)
		{
			param->err += param->dy;
			a->x += param->sx;
		}
		if (param->e2 <= param->dx)
		{
			param->err += param->dx;
			a->y += param->sy;
		}
	}
	free(a);
	free(b);
	free(param);
}
