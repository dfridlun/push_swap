/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formathandling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:01:34 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:34:48 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/ft_printf.h"

int	ft_putchar_pf(char c)
{
	return (write (1, &c, 1));
}

int	ft_puthex(unsigned long n, int uppercase)
{
	int		count;
	char	*hex;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar_pf(hex[n % 16]);
	return (count);
}

int	ft_putnbr_pf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}

int	ft_putstr_pf(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, len));
}

int	ft_put_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_unsigned(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}
