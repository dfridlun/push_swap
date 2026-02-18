/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:15:20 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/19 20:24:08 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

static void	free_split(char **split_result)
{
	int	i;

	i = 0;
	if (!split_result)
		return ;
	while (split_result[i])
	{
		free(split_result[i]);
		split_result[i] = NULL;
		i++;
	}
	free(split_result);
	split_result = NULL;
}

static void	execute_sorting(t_node **a, t_node **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int ac, char *av[])
{
	t_node	*a;
	t_node	*b;
	char	**split_av;

	split_av = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2 && av[1])
		split_av = split(av[1], ' ');
	if (split_av)
		init_stack_a(&a, split_av);
	else
		init_stack_a(&a, av + 1);
	execute_sorting(&a, &b);
	free_stack(&a);
	if (split_av)
	{
		free_split(split_av);
		split_av = NULL;
	}
	return (0);
}
