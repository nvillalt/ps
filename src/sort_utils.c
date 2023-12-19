/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:48:28 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 11:06:26 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest_biggest(t_data **a, t_data **b, t_data **target)
{
	t_data	*aux;
	int		max;

	aux = *a;
	max = INT_MAX;
	while (aux)
	{
		if (aux->value > (*b)->value && aux->value < max)
		{
			max = aux->value;
			*target = aux;
		}
		aux = aux->next;
		if (aux == *a)
			break ;
	}
	return (max);
}

t_data	*smallest_node(t_data **stack)
{
	t_data	*aux;
	t_data	*smallest;
	int		min;

	min = INT_MAX;
	aux = *stack;
	smallest = NULL;
	if (!stack)
		return (NULL);
	while (aux)
	{
		if (aux->index < min)
		{
			min = aux->index;
			smallest = aux;
		}
		aux = aux->next;
		if (aux == *stack)
			break ;
	}
	return (smallest);
}

void	set_targets(t_data **stack_a, t_data **stack_b)
{
	t_data	*b;
	t_data	*target;
	int		max;

	b = *stack_b;
	target = NULL;
	while (b)
	{
		max = get_smallest_biggest(stack_a, &b, &target);
		if (max == INT_MAX)
		{
			target = smallest_node(stack_a);
			b->target = target;
		}
		else
			b->target = target;
		b = b->next;
		if (b == *stack_b && b->next->target != NULL)
			break ;
	}
}
