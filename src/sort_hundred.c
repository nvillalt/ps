/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:21:26 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/17 20:09:03 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stacks(t_data **stack_a, t_data **stack_b)
{
	t_data	*pt_cheap;

	pt_cheap = retrieve_cheapest(stack_b);
	if (!pt_cheap || !stack_b)
		return ;
	if (pt_cheap->above_half == 0 && pt_cheap->target->above_half == 0)
		actualise_rrr(stack_a, stack_b, pt_cheap);
	else if (pt_cheap->above_half == 1 && pt_cheap->target->above_half == 1)
		actualise_rr(stack_a, stack_b, pt_cheap);
	if (pt_cheap != *stack_b)
		single_rotate(stack_b, pt_cheap, 'b');
	if (pt_cheap->target != *stack_a)
		single_rotate(stack_a, pt_cheap->target, 'a');
	push_pa(stack_a, stack_b);
}

void	prep_stacks(t_data **stack_a, t_data **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	set_half_index(stack_a);
	set_half_index(stack_b);
	set_targets(stack_a, stack_b);
	get_cost(stack_a, stack_b);
	get_cheapest(stack_b);
}

void	sort_hundred(t_data **stack_a, t_data **stack_b)
{
	t_data	*aux;
	int		len;

	len = list_len(stack_a);
	while (len-- > 3)
		push_pb(stack_a, stack_b);
	if (!stack_a || !stack_b)
		return ;
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
