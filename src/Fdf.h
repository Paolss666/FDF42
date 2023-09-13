/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:16:32 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/07 15:48:30 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH 100000
# define WINDOW_HEIGHT 30000
# define MLX_ERROR 1
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "X11/X.h"      // verifier
# include "X11/keysym.h" // must dans le ft de loop
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 768
# define DEFAULT_ANG 0.523599

/*
1) read file 
	- get height(how many lines) of the text
	- get width (how many numbers in line)
	- allocate memory for **int by useing width and heicht (ft_split())
	- read a file and write number into **int matrix;
		by using ft_split et ft_atoi()
--------------------------------
2) drawing line function (google Bresenham algo)
  -	find by how much we need to increase x and by how much we need to incres y
   by using float.
   Exabple: 
   x = 2; x1 = 4;
   y = 2; y1 = 6;
   steps for x: 2
   steps for y: 4
   that means that y should grow 2 times faster than x
   ewery loop step: y+= 1 and x += 05
   after 4 steps x and y will be equal with x1, y1;
   
*/

// void	*mlx_init(void);
// PERROR => print a sysem error message;
// describes the error code passed in the argument

// comprendere come funziona la libreria.

// typedef struct s_data
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// }				t_data;

/*
/ CREARE STRUTTURA PER TUTTO IL PROGRAMMA.
// credo che per adesso bisogna creare una struttura 
// che prende tutti i dati, y, x, z, len, last, 
// la scale, l'angolo,  isometria. 
// il punto preciso dove si trova (win_x  win_y);
//  mlx_ptr, win_ptr ==> per la windows. 
*/

typedef struct s_z
{
	int				altitude;
	int				color;
}					t_z;

typedef struct s_stack
{
	t_z				*z;
	struct s_stack	*next;
}					t_stack;

typedef struct s_matrix
{
	t_z				z;
}					t_matrix;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	t_matrix		**matrix;
	t_stack			*stack;
	int				width;
	int				height;
	int				zoom;
	int				color;
	int				x_pos;
	int				y_pos;
	int				bpp;
	int				size_line;
	int				endian;
	int				altitude;
	int				project;
	int				rot;
	double			def_ang;
	double			alpha;
	double			beta;
	double			teta;
}					t_fdf;

typedef struct s_param
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_param;

// ----- MLX ------//
int					esc_close(int key, t_fdf *param);
int					close_win(t_fdf *param);

// ----- ALGO BRESENHAMV -----  //
int					compare(int a, int b);
void				put_pixel(t_fdf *fdf, int x, int y);
t_param				*init_param(t_point *a, t_point *b);
void				bresnham(t_fdf *fdf, t_point *a, t_point *b);

void				ft_draw(t_fdf *fdf);
void				set_ypixel(t_fdf *fdf, int x, int y);
void				set_xpixel(t_fdf *fdf, int x, int y);
t_point				*projection(t_point *p, t_fdf *fdf);

// -------- ERREUR-------//

void				print_error(int error);
int					free_fdf(t_fdf *fdf);
void				free_line(char *line);
void				print_error_free_fdf(int error, t_fdf *fdf);
int					check_filename(char *filename, t_fdf *fdf);

// ------- UTILS ------//

int					ft_atoi_hex(char *str);
int					fill_stack(char **sec_split, t_stack **stack);
t_point				*point_init(int x, int y, t_fdf *fdf);
void				fill_data(t_matrix *matrix, t_stack **stack, t_fdf *fdf);
t_stack				*read_map(int fd, int *height, int *width, int *check_fd);
t_matrix			**create_matrix(t_fdf *fdf, t_stack *stack);
void				iso(int *x, int *y, int z, double teta);
void				x_rotation(int *x, int *y, int *z, double teta);
void				y_rotation(int *x, int *y, int *z, double teta);
void				z_rotation(int *x, int *y, int *z, double teta);

#endif