/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:21:26 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 11:02:58 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_ra(t_data **stack_a, t_data **node)
{
	t_data	*a;
	int		counter;
	int		len;
	int		i;

	a = *stack_a;
	counter = 0;
	i = 0;
	len = list_len(stack_a);
	while (i < len)
	{
		while (a->group != 0 && a->group != 1 && i < len)
		{
			counter++;
			a = a->next;
			i++;
		}
		*node = a;
		i++;
	}
	return (counter);
}

static int	count_rra(t_data **stack_a, t_data **node)
{
	t_data	*a;
	int		counter;
	int		len;
	int		i;

	a = *stack_a;
	counter = 0;
	i = 0;
	len = list_len(stack_a);
	while (i < len)
	{
		while (a->group != 0 && a->group != 1 && i < len)
		{
			counter++;
			a = a->back;
			i++;
		}
		*node = a;
		i++;
	}
	return (counter);
}

static void	set_stack(t_data **stack_a, t_data **stack_b)
{
	t_data	*node_ra;
	t_data	*node_rra;
	int		counter_ra;
	int		counter_rra;

	node_ra = NULL;
	node_rra = NULL;
	while ((*stack_a)->group == 0 || (*stack_a)->group == 1)
		push_pb(stack_a, stack_b);
	set_half_index(stack_a);
	counter_ra = count_ra(stack_a, &node_ra);
	counter_rra = count_rra(stack_a, &node_rra);
	if (counter_ra < counter_rra)
		single_rotate(stack_a, node_ra, 'a');
	else
		single_rotate(stack_a, node_rra, 'a');
}

void	sort_more(t_data **stack_a, t_data **stack_b)
{
	t_data	*aux;
	int		len;

	len = list_len(stack_a);
	while (len > 3)
	{
		len = list_len(stack_a);
		set_stack(stack_a, stack_b);
		if (len > 3 && (*stack_a)->group > 1)
			push_pb(stack_a, stack_b);
	}
	if (!check_order(stack_a))
		sort_three(stack_a);
	while (stack_b)
	{
		if (!stack_b || !(*stack_b))
			break ;
		prep_stacks(stack_a, stack_b);
		move_stacks(stack_a, stack_b);
	}
	set_half_index(stack_a);
	aux = smallest_node(stack_a);
	single_rotate(stack_a, aux, 'a');
}
