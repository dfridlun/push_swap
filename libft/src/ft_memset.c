/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:56:58 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:36 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	sym;
	size_t			i;

	i = 0;
	sym = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < len)
	{
		ptr[i] = sym;
		i++;
	}
	return (s);
}
