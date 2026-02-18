/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:07:01 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:28 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			i;
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	i = 0;
	cstr1 = (unsigned char *) str1;
	cstr2 = (unsigned char *) str2;
	while (i < len)
	{
		if (cstr1[i] != cstr2[i])
			return (cstr1[i] - cstr2[i]);
		i++;
	}
	return (0);
}
