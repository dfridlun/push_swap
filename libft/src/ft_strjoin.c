/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:39:21 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:36:04 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *str1, char const *str2)
{
	char		*res;
	size_t		i;
	size_t		j;

	if (!str1 || !str2)
		return (0);
	res = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (str1[i] != '\0')
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		res[i + j] = str2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
