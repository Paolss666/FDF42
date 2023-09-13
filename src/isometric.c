/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:32:45 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/03 14:42:43 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	iso(int *x, int *y, int z, double teta)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(teta);
	*y = (previous_x + previous_y) * sin(teta) - z;
}

/*
Questa funzione esegue una rotazione sull'asse x dei punti tridimensionali.
Prende in input i puntatori x, y e z,
che rappresentano le coordinate del punto tridimensionale.
L'angolo teta specifica l'angolo di rotazione sull'asse x.
La funzione calcola le nuove coordinate y e z del punto dopo la rotazione 
e le aggiorna utilizzando i puntatori.
La coordinata x non viene modificata in questa rotazione.
Assicurati che teta sia espressa in radianti 
anziché gradi per evitare errori di calcolo.
*/

void	x_rotation(int *x, int *y, int *z, double teta)
{
	(void)(x);
	*y = *y * cos(teta) + *z * sin(teta);
	*z = -(*y) * sin(teta) + *z * (cos(teta));
}

/*
uesta funzione esegue una rotazione sull'asse y dei punti tridimensionali.
Prende in input i puntatori x, y e z, 
che rappresentano le coordinate del punto tridimensionale.
L'angolo teta specifica l'angolo di rotazione sull'asse y.
La funzione calcola le nuove coordinate x e z del punto dopo
la rotazione e le aggiorna utilizzando i puntatori.
La coordinata y non viene modificata in questa rotazione.
*/

void	y_rotation(int *x, int *y, int *z, double teta)
{
	(void)(y);
	*x = *x * cos(teta) + *z * sin(teta);
	*z = -(*x) * sin(teta) + *z * (cos(teta));
}

void	z_rotation(int *x, int *y, int *z, double teta)
{
	(void)(z);
	*x = *x * cos(teta) - *y * sin(teta);
	*y = (*x) * sin(teta) + *y * (cos(teta));
}

/*
Questa funzione esegue una rotazione sull'asse z dei punti tridimensionali.
Prende in input i puntatori x, y e z,
che rappresentano le coordinate del punto tridimensionale. 
L'angolo teta specifica l'angolo di rotazione sull'asse z.
La funzione calcola le nuove coordinate x e y del punto dopo la rotazione 
e le aggiorna utilizzando i puntatori.
La coordinata z non viene modificata in questa rotazione.
*/

// int main()
// {
//     t_point point = {10, 20, 30};

//     // Test delle rotazioni
//     double x_angle = M_PI / 4; // 
//Rotazione sull'asse x di 45 gradi (pi/4 radianti)
//     double y_angle = M_PI / 3; 
// Rotazione sull'asse y di 60 gradi (pi/3 radianti)
//     double z_angle = M_PI / 6; 
// Rotazione sull'asse z di 30 gradi (pi/6 radianti)

//     printf("Punto originale: (%d, %d, %d)\n", point.x, point.y, point.z);

//     x_rotation(&point.x, &point.y, &point.z, x_angle);
//     printf("Punto dopo rotazione x:
// (%d, %d, %d)\n", point.x, point.y, point.z);

//     y_rotation(&point.x, &point.y, &point.z, y_angle);
//     printf("Punto dopo rotazione y:
// (%d, %d, %d)\n", point.x, point.y, point.z);

//     z_rotation(&point.x, &point.y, &point.z, z_angle);
//     printf("Punto dopo rotazione z: (%d, %d, %d)\n", 
		// point.x, point.y, point.z);

//     // Riportiamo il punto alle coordinate originali per i test successivi
//     point.x = 10;
//     point.y = 20;
//     point.z = 30;

//     // Test della proiezione isometrica
//     double iso_angle = M_PI / 6; 
	// Angolo di proiezione isometrica di 30 gradi (pi/6 radianti)

//     printf("Punto originale: (%d, %d, %d)\n", point.x, point.y, point.z);

//     iso(&point.x, &point.y, point.z, iso_angle);
//     printf("Punto dopo proiezione isometrica: (%d, %d)\n", point.x, point.y);

//     return 0;
// }