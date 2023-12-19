/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:28:49 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 21:55:09 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_params(int argc, char **argv)
{
	char	**params;
	char	*str;

	str = join_params(argc, argv);
	if (!str)
		return (NULL);
	params = ft_split(str, ' ');
	free(str);
	if (!params)
		return (NULL);
	if (!check_num(params) || !rep_params(params) || !check_len(params))
	{
		write(2, "Error.\n", 7);
		free_params(params);
		return (0);
	}
	return (params);
}

static int	to_stack(char **params, t_data **stack_a)
{
	int			i;
	long int	num;
	t_data		*node;

	i = 0;
	node = NULL;
	num = 0;
	while (params[i])
	{
		num = ft_atoi(params[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		node = new_node(num);
		add_back_lst(stack_a, node);
		i++;
	}
	return (1);
}

static void	init_index(t_data **stack_a, int index)
{
	t_data	*aux;
	int		len;
	int		min;
	int		i;
	int		div;

	i = 0;
	len = list_len(stack_a);
	aux = *stack_a;
	if (len > 2)
		div = len / 3;
	while (i < len || index < len)
	{
		min = find_min_no_index(stack_a);
		if (aux->value == min)
		{
			aux->group = index / div;
			aux->index = index;
			index++;
		}
		aux = aux->next;
		i++;
	}
}

int	check_order(t_data **stack_a)
{
	t_data	*temp;

	temp = *stack_a;
	while (temp->next != *stack_a)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_and_init(int argc, char **argv, t_data **stack_a)
{
	char	**params;
	int		flag;

	flag = 0;
	params = get_params(argc, argv);
	if (!params)
		return (0);
	flag = to_stack(params, stack_a);
	if (!flag || rep_stack(stack_a) > 0)
	{
		write(2, "Error.\n", 7);
		free_params(params);
		return (0);
	}
	if (check_order(stack_a) || !flag)
	{
		free_params(params);
		return (0);
	}
	init_index(stack_a, 0);
	free_params(params);
	return (1);
}
