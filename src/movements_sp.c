/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c    	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:53:46 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/02 12:34:05 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_swap(int	*a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_sasb(t_data **stack, int op)
{
	if (!(*stack) || !stack || (*stack)->next == NULL)
		return ;
	ft_swap(&(*stack)->value, &(*stack)->next->value);
	ft_swap(&(*stack)->index, &(*stack)->next->index);
	if (op == 0)
		write(1, "sa\n", 3);
	else if (op == 1)
		write(1, "sb\n", 3);
}

void	swap_ss(t_data **stack_a, t_data **stack_b)
{
	if (!(*stack_a) || !(*stack_b) || !stack_a || !stack_b)
		return ;
	swap_sasb(stack_a, 2);
	swap_sasb(stack_b, 2);
	write(1, "ss\n", 3);
}

void	push_pa(t_data **stack_a, t_data **stack_b)
{
	t_data	*aux;
	t_data	*last;
	int		len;

	aux = *stack_b;
	last = list_last(stack_a);
	len = list_len(stack_b);
	if (len > 1)
	{
		add_front_lst(stack_a, stack_b, &aux);
	}
	if (len == 1)
	{
		(*stack_a)->back = aux;
		last->next = aux;
		aux->next = *stack_a;
		aux->back = last;
		*stack_b = NULL;
		stack_b = NULL;
		*stack_a = aux;
	}
	write(1, "pa\n", 3);
}

void	push_pb(t_data **stack_a, t_data **stack_b)
{
	t_data	*aux;
	t_data	*last;
	t_data	*last_b;

	aux = *stack_a;
	last = list_last(stack_a);
	last_b = list_last(stack_b);
	if (!*stack_a || !stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	if (!*stack_b || !stack_b)
		init_stack(stack_b, &aux);
	else if (*stack_b)
	{
		(*stack_b)->back = aux;
		aux->next = *stack_b;
		aux->back = last_b;
		last_b->next = aux;
		*stack_b = aux;
	}
	last->next = *stack_a;
	(*stack_a)->back = last;
	write(1, "pb\n", 3);
}
