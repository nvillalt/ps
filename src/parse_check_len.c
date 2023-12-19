/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_len.c    	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:53:46 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/02 12:34:05 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int	skip_zero(char *params)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (params[j] == '-' || params[j] == '+')
	{
		count++;
		j++;
	}
	while (params[j] == '0')
		j++;
	while (params[j] != '0' && params[j] != '\0')
	{
		j++;
		count++;
	}
	return (count);
}

int		check_len(char **params)
{
	int	count;
	int	i;

	i = 0;
	while (params[i])
	{
		if (ft_strlen(params[i]) == 1 && (params[i][0] == '-'
			|| params[i][0] == '+'))
			return (0);
		count = skip_zero(params[i]);
		if ((params[i][0] == '-' || params[i][0] == '+')
			&& count > 11)
			return (0);
		if ((params[i][0] != '-' || params[i][0] != '+')
			&& count > 10)
			return (0);
		i++;
	}
	return (1);
}