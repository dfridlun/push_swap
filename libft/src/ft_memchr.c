/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:52:45 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:25 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*cstr;
	unsigned char	sym;

	sym = c;
	i = 0;
	cstr = (unsigned char *) s;
	while (i < len)
	{
		if (cstr[i] == sym)
			return ((unsigned char *)(cstr + i));
		i++;
	}
	return (0);
}
