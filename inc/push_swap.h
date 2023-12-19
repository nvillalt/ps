/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:18:21 by nvillalt          #+#    #+#             */
/*   Updated: 2023/12/19 21:29:03 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	int				value;
	int				index;
	int				stack_index;
	int				above_half;
	int				cheapest;
	int				cost;
	int				group;
	struct s_data	*next;
	struct s_data	*back;
	struct s_data	*target;
}t_data;

//	PARSE FUNCTIONS
int		check_and_init(int argc, char **argv, t_data **stack_a);
int		check_order(t_data **stack_a);

// PARSE_UTILS FUNCTIONS
void	free_params(char **params);
int		check_num(char **argv);
int		rep_params(char **argv);
int		check_len(char **params);
char	*join_params(int argc, char **argv);

// LIST_UTILS FUNCTIONS
t_data	*new_node(int value);
t_data	*list_last(t_data **head);
void	add_back_lst(t_data **head, t_data *node);
void	add_front_lst(t_data **stack_a, t_data **stack_b, t_data **aux);
void	free_stack(t_data **head);
int		check_max(t_data **head);
int		list_len(t_data **head);
int		find_min_no_index(t_data **stack_a);
int		rep_stack(t_data **stack);

void	print_list(t_data **stack_a);

/* SORT_ALGORITHM FUNCTIONS */
void	sort_algorithm(t_data **stack_a, t_data **stack_b);
void	sort_three(t_data **stack_a);
void	sort_more(t_data **stack_a, t_data **stack_b);

/* SORT_UTILS FUNCTIONS */
t_data	*retrieve_cheapest(t_data **stack);
t_data	*smallest_node(t_data **stack);
void	set_targets(t_data **stack_a, t_data **stack_b);
void	set_half_index(t_data **stack);
void	get_cost(t_data **stack_a, t_data **stack_b);
void	get_cheapest(t_data **stack_b);

/* ALGORITHM_MOVEMENTS FUNCTIONS */
void	actualise_rr(t_data **stack_a, t_data **stack_b, t_data *cheapest);
void	actualise_rrr(t_data **stack_a, t_data **stack_b, t_data *cheapest);
void	single_rotate(t_data **stack, t_data *pt_cheap, char c);

/* MOVEMENTS FUNCTIONS */
void	swap_sasb(t_data **stack, int op);
void	swap_ss(t_data **stack_a, t_data **stack_b);
void	push_pa(t_data **stack_a, t_data **stack_b);
void	push_pb(t_data **stack_a, t_data **stack_b);
void	rotate_rarb(t_data **stack, int op);
void	rotate_rr(t_data **stack_a, t_data **stack_b);
void	revrot_rrarrb(t_data **stack, int op);
void	revrot_rrr(t_data **stack_a, t_data **stack_b);
void	init_stack(t_data **stack_b, t_data **aux);

/* OPTIMISATION ATTEMPT */
void	sort_hundred(t_data **stack_a, t_data **stack_b);
void	prep_stacks(t_data **stack_a, t_data **stack_b);
void	move_stacks(t_data **stack_a, t_data **stack_b);

#endif