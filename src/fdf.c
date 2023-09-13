/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:34:24 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/07 13:37:52 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	free_matrix(t_matrix **matrix, int height)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_stack(t_stack *stack, t_fdf *fdf)
{
	t_stack	*ptr;
	t_stack	*suiv;

	while (stack != NULL)
	{
		suiv = stack->next;
		free(stack->z);
		stack = suiv;
	}
	while (fdf->stack)
	{
		ptr = fdf->stack->next;
		free(fdf->stack);
		fdf->stack = ptr;
	}
	free(fdf->stack);
}

void	init_camera(t_fdf *fdf)
{
	if (fdf->width >= 400)
		fdf->zoom = 1;
	else if (fdf->width >= 300)
		fdf->zoom = 5;
	else
		fdf->zoom = 20;
	fdf->x_pos = (WIDTH / 2) - (fdf->width / 2);
	fdf->y_pos = (HEIGHT / 2) - (fdf->height / 2);
	fdf->project = 1;
	fdf->def_ang = DEFAULT_ANG;
	fdf->altitude = 1;
}

void	fdf_init(t_fdf *fdf, char *filename, int *check_fd)
{
	t_stack	*stack;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_free_fdf(1, fdf);
	check_filename(filename, fdf);
	fdf->stack = read_map(fd, &fdf->height, &fdf->width, check_fd);
	if (*check_fd == -1)
		print_error_free_fdf(3, fdf);
	else if (*check_fd == -2)
		print_error_free_fdf(4, fdf);
	stack = fdf->stack;
	fdf->alpha = 0;
	fdf->teta = 0;
	fdf->beta = 0;
	init_camera(fdf);
	fdf->matrix = create_matrix(fdf, stack);
	free_stack(fdf->stack, fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	int		check_fd;

	if (ac == 2)
	{
		check_fd = 0;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			free_fdf(fdf);
		fdf_init(fdf, av[1], &check_fd);
		free_stack(fdf->stack, fdf);
		ft_draw(fdf);
		free_matrix(fdf->matrix, fdf->height);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIDTH - 90, 10, 0x8cff00,
			"By NICOLA");
		mlx_hook(fdf->win_ptr, 2, 0L, &esc_close, fdf);
		mlx_hook(fdf->win_ptr, 17, KeyPressMask, &close_win, fdf);
		mlx_loop(fdf->mlx_ptr);
		free(fdf);
	}
	else
		print_error(2);
	return (0);
}
