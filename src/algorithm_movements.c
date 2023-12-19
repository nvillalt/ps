/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:48:28 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 10:52:34 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_rotate(t_data **stack, t_data *node, char c)
{
	while (node != *stack)
	{
		if (c == 'a')
		{
			if (node->above_half == 1)
				rotate_rarb(stack, 0);
			else if (node->above_half == 0)
				revrot_rrarrb(stack, 0);
		}
		if (c == 'b')
		{
			if (node->above_half == 1)
				rotate_rarb(stack, 1);
			else if (node->above_half == 0)
				revrot_rrarrb(stack, 1);
		}
	}
}

void	actualise_rr(t_data **stack_a, t_data **stack_b, t_data *pt_cheap)
{
	while (*stack_a != pt_cheap->target && *stack_b != pt_cheap)
		rotate_rr(stack_a, stack_b);
	set_half_index(stack_a);
	set_half_index(stack_b);
}

void	actualise_rrr(t_data **stack_a, t_data **stack_b, t_data *pt_cheap)
{
	while (*stack_a != pt_cheap->target && *stack_b != pt_cheap)
		revrot_rrr(stack_a, stack_b);
	set_half_index(stack_a);
	set_half_index(stack_b);
}
