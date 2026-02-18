/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:25:41 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/31 21:10:47 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

int	stack_len(t_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_node	*smallest_node(t_node *stack)
{
	long		min;
	t_node		*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*big_node(t_node *stack)
{
	long			big;
	t_node			*big_node;

	if (!stack)
		return (NULL);
	big = LONG_MIN;
	big_node = NULL;
	while (stack)
	{
		if (stack->nbr > big)
		{
			big = stack->nbr;
			big_node = stack;
		}
		stack = stack->next;
	}
	return (big_node);
}
