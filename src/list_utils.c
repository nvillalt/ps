/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:53:46 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/15 13:57:54 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*new_node(int value)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->value = value;
	new->index = -1;
	new->stack_index = 0;
	new->above_half = 0;
	new->cheapest = 0;
	new->group = 0;
	new->next = NULL;
	new->back = NULL;
	new->target = NULL;
	return (new);
}

void	free_stack(t_data **head)
{
	t_data	*aux;
	t_data	*next;

	if (!(*head) || !head)
		return ;
	aux = *head;
	while (aux && aux->next != *head)
	{
		next = aux->next;
		free(aux);
		aux = next;
	}
	free(aux);
	*head = NULL;
}

void	add_front_lst(t_data **stack_a, t_data **stack_b, t_data **aux)
{
	t_data	*last_a;
	t_data	*last_b;

	last_a = list_last(stack_a);
	last_b = list_last(stack_b);
	*stack_b = (*stack_b)->next;
	(*stack_b)->back = last_b;
	last_b->next = *stack_b;
	(*stack_a)->back = *aux;
	(*aux)->next = *stack_a;
	(*aux)->back = last_a;
	last_a->next = *aux;
	*stack_a = *aux;
}

void	add_back_lst(t_data **head, t_data *node)
{
	t_data	*temp;

	if (!head || !node)
		return ;
	if (*head == NULL)
	{
		*head = node;
		node->next = node;
		node->back = node;
		return ;
	}
	temp = *head;
	while (temp)
	{
		if (temp->next == *head)
			break ;
		temp = temp->next;
	}
	(*head)->back = node;
	node->next = *head;
	node->back = temp;
	temp->next = node;
}

int	list_len(t_data **stack)
{
	t_data	*temp;
	int		n;

	n = 0;
	temp = *stack;
	while (temp)
	{
		n++;
		if (temp->next == *stack)
			break ;
		temp = temp->next;
	}
	return (n);
}
