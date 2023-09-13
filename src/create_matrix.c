/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:04:29 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/03 14:39:24 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	fill_data(t_matrix *matrix, t_stack **stack, t_fdf *fdf)
{
	int	width;

	width = fdf->width;
	while (width--)
	{
		matrix[width].z.altitude = (*stack)->z->altitude;
		matrix[width].z.color = (*stack)->z->color;
		(*stack) = (*stack)->next;
	}
}

t_matrix	**create_matrix(t_fdf *fdf, t_stack *stack)
{
	t_matrix	**matrix;
	int			height;
	int			width;

	height = fdf->height;
	width = fdf->width;
	matrix = (t_matrix **)malloc(sizeof(t_matrix *) * (height + 1));
	if (!matrix)
		return (NULL);
	matrix[height] = NULL;
	while (height > 0)
	{
		height--;
		matrix[height] = (t_matrix *)malloc(sizeof(t_matrix) * (width));
		if (!matrix[height])
			return (NULL);
		fill_data(matrix[height], &stack, fdf);
	}
	return (matrix);
}

// void print_map(t_matrix **matrix, t_fdf *fdf)
// {
//     for (int i = 0; i < fdf->height; i++)
//     {
//         for (int j = 0; j < fdf->width; j++)
//         {
//             printf("Altitude: %d, Color: %X\n",
// matrix[i][j].z.altitude, matrix[i][j].z.color);
//         }
//     }
// }

// int main()
// {
//     // Creiamo un esempio di dati per testare le funzioni
//     t_fdf fdf;
//     fdf.height = 3; 
// Assicurati che queste 
//dimensioni siano corrette in base ai tuoi dati di input.
//     fdf.width = 4;  
// Assicurati che queste dimensioni 
//siano corrette in base ai tuoi dati di input.

//     // Allochiamo dinamicamente
// un array di puntatori a t_stack e riempiamo alcuni dati di esempio
//     t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
//     stack->z = (t_z *)malloc(sizeof(t_z));
//     stack->z->altitude = 10;
//     stack->z->color = 0xFF0000;
//     stack->next = (t_stack *)malloc(sizeof(t_stack));
//     stack->next->z = (t_z *)malloc(sizeof(t_z));
//     stack->next->z->altitude = 20;
//     stack->next->z->color = 0x00FF00;
//     stack->next->next = (t_stack *)malloc(sizeof(t_stack));
//     stack->next->next->z = (t_z *)malloc(sizeof(t_z));
//     stack->next->next->z->altitude = 30;
//     stack->next->next->z->color = 0x0000FF;
//     stack->next->next->next = NULL;

//     // Creiamo la matrice utilizzando la funzione create_matrix
//     t_matrix **matrix = create_matrix(&fdf, stack);

//     // Stampa la matrice di test
//     print_map(matrix, &fdf);

//     // Libera la memoria allocata per la matrice e la pila
//     for (int i = 0; i < fdf.height; i++)
//     {
//         free(matrix[i]);
//     }
//     free(matrix);

//     t_stack *current = stack;
//     t_stack *next;
//     while (current != NULL)
//     {
//         next = current->next;
//         free(current->z);
//         free(current);
//         current = next;
//     }

//     return 0;
// }
