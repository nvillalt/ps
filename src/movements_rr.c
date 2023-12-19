/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:21:26 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/15 20:05:45 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_data **stack, t_data **aux)
{
	*stack = *aux;
	(*aux)->next = *aux;
	(*aux)->back = *aux;
}

void	rotate_rarb(t_data **stack, int op)
{
	if (*stack == NULL || stack == NULL)
		return ;
	*stack = (*stack)->next;
	if (op == 0)
		write(1, "ra\n", 3);
	else if (op == 1)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_data **stack_a, t_data **stack_b)
{
	if (!(*stack_a) || !(*stack_b) || !stack_a || !stack_b)
		return ;
	rotate_rarb(stack_a, 2);
	rotate_rarb(stack_b, 2);
	write(1, "rr\n", 3);
}

void	revrot_rrarrb(t_data **stack, int op)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->back;
	if (op == 0)
		write(1, "rra\n", 4);
	else if (op == 1)
		write(1, "rrb\n", 4);
}

void	revrot_rrr(t_data **stack_a, t_data **stack_b)
{
	if (!(*stack_a) || !(*stack_b) || !stack_a || !stack_b)
		return ;
	revrot_rrarrb(stack_a, 2);
	revrot_rrarrb(stack_b, 2);
	write(1, "rrr\n", 4);
}
