/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:53:56 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 10:54:06 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_data **stack_a)
{
	t_data	*temp;
	int		i;
	int		len;

	i = 0;
	len = list_len(stack_a);
	temp = *stack_a;
	while (i < len)
	{
		printf("-------NODE----------------\n");
		printf("Value: %d\n", temp->value);
		printf("Index General: %d\n", temp->index);
		printf("Stack Index (Cambia): %d\n", temp->stack_index);
		printf("Above Half: %d\n", temp->above_half);
		printf("Cheapest: %d\n", temp->cheapest);
		printf("Cost: %d\n", temp->cost);
		printf("Group: %d\n", temp->group);
		printf("Node Next: %d\n", temp->next->value);
		printf("Node Prev: %d\n", temp->back->value);
		if (temp->target)
			printf("Target Node: %d\n", temp->target->value);
		printf("----------------------------\n");
		temp = temp->next;
		i++;
	}
}
