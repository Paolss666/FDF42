/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:00:11 by npaolett          #+#    #+#             */
/*   Updated: 2023/08/02 19:42:20 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		if (!(*stack))
			*stack = new;
		else
		{
			new->next = *stack;
			*stack = new;
		}
	}
}

int	fill_stack(char **sec_split, t_stack **stack)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (1);
	new_stack->z = (t_z *)malloc(sizeof(t_z));
	if (!new_stack->z)
	{
		free(new_stack);
		return (1);
	}
	new_stack->z->altitude = ft_atoi(sec_split[0]);
	if (sec_split[1] != NULL)
		new_stack->z->color = ft_atoi_hex(sec_split[1]);
	else
		new_stack->z->color = -1;
	new_stack->next = NULL;
	stack_add_front(stack, new_stack);
	return (0);
}
