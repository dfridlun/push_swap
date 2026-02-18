/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:17:15 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/02 15:11:52 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

static void	rev(t_node **stack)
{
	t_node	*last;

	if (!stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **a, bool print)
{
	rev(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool print)
{
	rev(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print)
{
	rev(a);
	rev(b);
	if (!print)
		ft_printf("rrr\n");
}
