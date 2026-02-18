/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:56:24 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:37:09 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	start = 0;
	end = ft_strlen(str);
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end > start && ft_strrchr(set, str[end - 1]))
		end--;
	res = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, str + start, end - start + 1);
	res[end - start] = '\0';
	return (res);
}
