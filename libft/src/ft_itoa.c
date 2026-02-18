/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:53:38 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:34:57 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

static int	nbr_count(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
		count = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static void	recursive(long n, char *str, int *index)
{
	if (n < 0)
	{
		str[*index] = '-';
		(*index)++;
		n = -n;
	}
	if (n / 10)
	{
		recursive(n / 10, str, index);
	}
	str[*index] = (n % 10) + '0';
	(*index)++;
}

char	*ft_itoa(int n)
{
	int		index;
	int		size;
	long	ln;
	char	*str;

	ln = n;
	size = nbr_count(ln);
	index = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
	{
		str[index] = '0';
	}
	recursive(ln, str, &index);
	return (str);
}
