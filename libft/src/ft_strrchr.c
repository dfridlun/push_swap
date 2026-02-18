/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:41:31 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:37:06 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			chr;

	i = 0;
	chr = c;
	res = NULL;
	while (s[i])
	{
		if (s[i] == chr)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == chr)
		res = (char *) &s[i];
	return (res);
}
