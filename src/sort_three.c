/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:52:17 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/08 16:33:45 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data **stack_a)
{
	if (check_max(stack_a) == (*stack_a)->value)
	{
		rotate_rarb(stack_a, 0);
		if (check_order(stack_a))
			return ;
		swap_sasb(stack_a, 0);
	}
	else if ((*stack_a)->value < (*stack_a)->next->value)
	{
		revrot_rrarrb(stack_a, 0);
		if (check_order(stack_a))
			return ;
		swap_sasb(stack_a, 0);
	}
	else
		swap_sasb(stack_a, 0);
}
