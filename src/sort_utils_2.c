/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:48:28 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 11:08:44 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*retrieve_cheapest(t_data **stack)
{
	t_data	*aux;

	aux = *stack;
	if (!stack || !aux || !(*stack))
		return (NULL);
	while (aux)
	{
		if (aux->cheapest == 1)
			return (aux);
		aux = aux->next;
		if (aux == *stack)
			break ;
	}
	return (NULL);
}

void	set_half_index(t_data **stack)
{
	t_data	*aux;
	int		len;
	int		i;

	aux = *stack;
	len = list_len(stack);
	if (!stack || !aux)
		return ;
	i = 0;
	while (aux)
	{
		aux->stack_index = i;
		if (i <= len / 2)
			aux->above_half = 1;
		else if (i > len / 2)
			aux->above_half = 0;
		i++;
		aux = aux->next;
		if (aux == *stack)
			break ;
	}
}

void	get_cost(t_data **stack_a, t_data **stack_b)
{
	t_data	*aux;
	int		len_a;
	int		len_b;

	len_a = list_len(stack_a);
	len_b = list_len(stack_b);
	aux = *stack_b;
	if (!stack_a || !stack_b || !aux)
		return ;
	while (aux)
	{
		aux->cost = aux->stack_index;
		if (aux->above_half == 0)
			aux->cost = len_b - (aux->stack_index);
		if (aux->target->above_half == 1)
			aux->cost += aux->target->stack_index;
		else
			aux->cost += len_a - (aux->target->stack_index);
		aux = aux->next;
		if (aux == *stack_b)
			break ;
	}
}

void	get_cheapest(t_data **stack_b)
{
	t_data	*aux;
	t_data	*cheapest_node;
	int		cheapest;

	aux = *stack_b;
	cheapest = INT_MAX;
	if (!stack_b || !aux)
		return ;
	while (aux)
	{
		if (aux->cost < cheapest)
		{
			cheapest = aux->cost;
			cheapest_node = aux;
		}
		aux = aux->next;
		if (aux == *stack_b)
			break ;
	}
	cheapest_node->cheapest = 1;
}
