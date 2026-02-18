/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:09:39 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/19 20:22:31 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

int	synt_error(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (ft_isdigit(*str_n))))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(ft_isdigit(str_n[1])))
		return (1);
	if (*str_n == '+' || *str_n == '-')
		str_n++;
	while (*str_n)
	{
		if (!ft_isdigit(*str_n))
			return (1);
		str_n++;
	}
	return (0);
}

int	dupe_error(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
