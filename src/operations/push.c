/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:07:39 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/05 18:04:06 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*push_node;

	if (!src || !*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->next = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
	}
	else
	{
		push_node->next = *dst;
		(*dst)->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
