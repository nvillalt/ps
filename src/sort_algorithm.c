/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:42:20 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 13:30:55 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_algorithm(t_data **stack_a, t_data **stack_b)
{
	if (list_len(stack_a) == 2
		&& ((*stack_a)->value > (*stack_a)->next->value))
		swap_sasb(stack_a, 0);
	else if (list_len(stack_a) == 3)
		sort_three(stack_a);
	else if (list_len(stack_a) > 3 && list_len(stack_a) < 500)
		sort_hundred(stack_a, stack_b);
	else
		sort_more(stack_a, stack_b);
	if (check_order(stack_a))
		return ;
}
