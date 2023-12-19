/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:21:01 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 21:54:06 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_no_index(t_data **stack_a)
{
	t_data	*aux;
	int		min;
	int		len;
	int		i;

	min = INT_MAX;
	len = list_len(stack_a);
	i = 0;
	aux = *stack_a;
	while (i < len)
	{
		if ((aux->index == -1) && (min > aux->value))
			min = aux->value;
		aux = aux->next;
		i++;
	}
	return (min);
}

int	check_max(t_data **head)
{
	int		max;
	t_data	*aux;

	aux = *head;
	max = (*head)->value;
	while (aux->next != *head)
	{
		if (aux->next->value > max)
			max = aux->next->value;
		aux = aux->next;
	}
	return (max);
}

t_data	*list_last(t_data **head)
{
	t_data	*aux;

	aux = *head;
	while (aux)
	{
		if (aux->next == *head)
			return (aux);
		aux = aux->next;
	}
	return (aux);
}

int	rep_stack(t_data **stack)
{
	t_data	*aux;
	t_data	*tmp;
	int		count;

	count = 0;
	tmp = *stack;
	if (tmp->value == tmp->next->value && list_len(stack) > 1)
		return (1);
	while (tmp->next != *stack)
	{
		aux = (*stack)->next;
		while (aux->next != *stack)
		{
			if (aux->value == (*stack)->value)
			{
				count++;
				break ;
			}
			aux = aux->next;
		}
		tmp = tmp->next;
	}
	return (count);
}