/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:17:27 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:34:30 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	digit;

	negative = 1;
	i = 0;
	digit = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		digit = 10 * digit + (str[i] - '0');
		i++;
	}
	return (digit * negative);
}
