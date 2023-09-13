/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 04:23:45 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/03 16:36:39 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"
// now here we need to get the heigth and the width th of the map
// and allocate the memory

int	ft_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_line_error(int width, int i, int *check_fd, char **split)
{
	free_tab(split);
	if (width > i)
	{
		*check_fd = -2;
		return (1);
	}
	return (0);
}

int	get_line_info(char *line, t_stack **stack, int *width, int *check_fd)
{
	int		i;
	char	**split;
	char	**sec_split;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		sec_split = ft_split(split[i], ',');
		if (fill_stack(sec_split, stack))
		{
			free_tab(sec_split);
			free_tab(split);
			*check_fd = -1;
			return (1);
		}
		free_tab(sec_split);
		i++;
	}
	if (check_line_error(*width, i, check_fd, split))
		return (1);
	return (0);
}

/*
Legge un file teto fd, analizz il 
contenuto del file e restituisce una struttura dati
che rappresenta la mappa letta.
height e width rappresentano effettivamente l'altezza e la lunghezza della mappa
*/

t_stack	*read_map(int fd, int *height, int *width, int *check_fd)
{
	char	*tmp;
	t_stack	*stack;
	int		i;
	int		check;

	i = 0;
	tmp = get_next_line(fd);
	if (!tmp)
		free_line(tmp);
	stack = NULL;
	*width = ft_words(tmp, ' ');
	while (tmp != NULL)
	{
		i++;
		check = get_line_info(tmp, &stack, width, check_fd);
		if (check != 0)
			return (0);
		free(tmp);
		tmp = get_next_line(fd);
	}
	*height = i;
	free(tmp);
	close(fd);
	return (stack);
}

// int main() {
//     int fd;
//     int height, width;
//     int check_fd = 0;

//     // Apri il file di input 
//(sostituisci "input.txt" con il nome del tuo file di input)
//     fd = open("../map/test_maps/42.fdf", O_RDONLY);
//     if (fd == -1) {
//         perror("Errore nell'apertura del file");
//         return 1;
//     }

//     // Leggi la mappa dal file utilizzando la funzione read_map
//     t_stack *map = read_map(fd, &height, &width, &check_fd);
//     close(fd);

//     if (map == NULL) {
//         printf("Errore nella lettura della mappa.\n");
//         return 1;
//     }

//     // Stampa la mappa letta
//     print_map(map, height, width);

//     // Esegui altre operazioni o liberare la memoria, se necessario.

//     return 0;
// }
