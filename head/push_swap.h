/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:13:24 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/19 18:10:17 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include "../libft/head/libft.h"
# include "../libft/head/ft_printf.h"
# include <unistd.h>

typedef struct s_stack_node
{
	long int				nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;

}	t_node;

int		synt_error(char *str_n);
int		dupe_error(t_node *a, int n);
int		stack_len(t_node *stack);
int		rr_cost_analysis(t_node *a, int a_len, int b_len);

char	**split(char *s, char c);

bool	is_sorted(t_node *stack);

void	prep_push(t_node **stack, t_node *top_node, char stack_name);
void	free_stack(t_node **stack);
void	free_error(t_node **a);
void	current_index(t_node *stack);
void	cheapest(t_node *stack);
void	init_nodes_a(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);
void	init_stack_a(t_node **a, char **av);
void	find_score(t_node	*a, t_node	*current_b);

t_node	*get_cheapest(t_node *stack);
t_node	*find_last(t_node *stack);
t_node	*big_node(t_node *stack);
t_node	*smallest_node(t_node *stack);

void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	sort_stacks(t_node **a, t_node **b);
void	sort_three(t_node **a);

#endif