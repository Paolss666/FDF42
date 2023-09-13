/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:47:22 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/03 16:38:06 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	print_error_free_fdf(int error, t_fdf *fdf)
{
	if (error == 1)
		write(2, "FILE ERROR.\n", 12);
	else if (error == 2)
		write(2, "Invalid Parameters.\n", 21);
	else if (error == 3)
		write(2, "Allocation Error.\n", 18);
	else if (error == 4)
		write(2, "Found wrong line leght Exiting.\n", 32);
	free(fdf);
	exit(1);
}

void	print_error(int error)
{
	if (error == 1)
		write(2, "FILE ERROR12.\n", 12);
	else if (error == 2)
		write(2, "Invalid Parameters.\n", 21);
	else if (error == 3)
		write(2, "Allocation Error.\n", 18);
	else if (error == 4)
		write(2, "Found wrong line leght Exiting.\n", 32);
	exit(1);
}

int	check_filename(char *filename, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'f')
	{
		print_error_free_fdf(1, fdf);
		exit(1);
	}
	return (0);
}

int	free_fdf(t_fdf *fdf)
{
	free(fdf);
	exit(1);
	return (0);
}

void	free_line(char *line)
{
	free(line);
	print_error(1);
	return ;
}
