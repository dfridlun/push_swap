/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:05:54 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/19 18:11:17 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

int	rr_cost_analysis(t_node *a, int a_len, int b_len)
{
	int	cost;

	cost = INT_MAX;
	if ((a->above_median) && (a->target_node->above_median))
	{
		if ((a->index) > (a->target_node->index))
			cost = a->index;
		else
			cost = a->target_node->index;
	}
	else if (!(a->above_median) && !(a->target_node->above_median))
	{
		if (a_len - (a->index) > b_len - (a->target_node->index))
			cost = a_len - (a->index);
		else
			cost = b_len - (a->target_node->index);
	}
	return (cost);
}
