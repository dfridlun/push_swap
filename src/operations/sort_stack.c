/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:18:49 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/17 15:30:28 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

static void	rotate_gen(t_node **a, t_node **b, t_node *cheap_node, bool rev)
{
	while (*a != cheap_node || *b != cheap_node->target_node)
	{
		if (*a != cheap_node && *b != cheap_node->target_node)
		{
			if (rev)
				rrr(a, b, false);
			else
				rr(a, b, false);
		}
		else if (*a != cheap_node)
		{
			if (rev)
				rra(a, false);
			else
				ra(a, false);
		}
		else if (*b != cheap_node->target_node)
		{
			if (rev)
				rrb(b, false);
			else
				rb(b, false);
		}
	}
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheap_n;

	cheap_n = get_cheapest(*a);
	if (cheap_n->above_median == cheap_n->target_node->above_median)
		rotate_gen(a, b, cheap_n, !cheap_n->above_median);
	prep_push(a, cheap_n, 'a');
	prep_push(b, cheap_n->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	if (!b || !*b)
		return ;
	init_nodes_b(*a, *b);
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
	if (!*b)
		return ;
}

static void	min_on_top(t_node **a)
{
	t_node	*smallest;

	current_index(*a);
	smallest = smallest_node(*a);
	while ((*a)->nbr != smallest->nbr)
	{
		if (smallest_node(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (stack_len(*a) > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	if (stack_len(*a) == 3 && !is_sorted(*a))
		sort_three(a);
	while (*b)
		move_b_to_a(a, b);
	current_index(*a);
	min_on_top(a);
}
