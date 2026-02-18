/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:19:06 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:34 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src_char;
	unsigned char	*dest_char;

	if (dest == NULL && src == NULL)
		return (dest);
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	if (dest <= src)
	{
		i = 0;
		while (len > i)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	}
	if (dest > src)
	{
		i = len;
		while (i-- > 0)
			dest_char[i] = src_char[i];
	}
	return (dest);
}
