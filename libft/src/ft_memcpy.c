/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:52:45 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:31 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src_char;
	unsigned char	*dest_char;

	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	src_char = (unsigned char *) src;
	dest_char = (unsigned char *) dest;
	while (i < len)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}
