/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:25:03 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 13:53:21 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_params(char **params)
{
	int	n;

	n = 0;
	while (params[n])
	{
		free(params[n]);
		n++;
	}
	free(params);
}

int	check_num(char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!argv[n] || argv[n][i] == '\0')
		return (0);
	while (argv[n])
	{
		i = 0;
		while ((argv[n][0] == '-' || argv[n][0] == '+') &&
			argv[n][++i] != '\0')
		{
			if (!ft_isdigit(argv[n][i]))
				return (0);
		}
		while (argv[n][i] != '\0')
		{
			if (!ft_isdigit(argv[n][i]))
				return (0);
			i++;
		}
		n++;
	}
	return (1);
}

int	rep_stack(t_data **stack)
{
	t_data	*aux;
	t_data	*tmp;
	int		count;

	count = 0;
	tmp = *stack;
	while (tmp->next != *stack)
	{
		aux = (*stack)->next;
		while (aux->next != *stack)
		{
			if (aux->value == (*stack)->value)
			{
				count++;
				break ;
			}
			aux = aux->next;
		}
		tmp = tmp->next;
	}
	return (count);
}

int	rep_params(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*join_params(int argc, char **argv)
{
	char	*join;
	char	*aux;
	int		i;

	i = 1;
	join = ft_strdup(argv[i]);
	if (!join)
		return (NULL);
	i++;
	while (i < argc)
	{
		aux = ft_strjoin(join, " ");
		if (!aux)
			return (NULL);
		free(join);
		join = ft_strjoin(aux, argv[i]);
		if (!join)
			return (NULL);
		free(aux);
		i++;
	}
	return (join);
}
