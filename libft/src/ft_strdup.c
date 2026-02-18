/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:22:16 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:36:01 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
