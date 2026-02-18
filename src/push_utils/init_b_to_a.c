/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:57:34 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/11 18:43:00 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

static void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_node *a, t_node *b)
{
	if (!a || !b)
		return ;
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
