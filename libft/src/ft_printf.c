/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:51:01 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:42 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../head/ft_printf.h"

int	ft_putptr_pf(void *ptr)
{
	int				count;

	if (ptr == NULL)
		count = ft_putstr_pf("(nil)");
	else
	{
		count = ft_putstr_pf("0x");
		count += ft_puthex((unsigned long)ptr, 0);
	}
	return (count);
}

int	ft_handle_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == '%')
		count = ft_putchar_pf('%');
	else if (format == 's')
		count = ft_putstr_pf(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr_pf(va_arg(args, int));
	else if (format == 'u')
		count = ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count = ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'p')
		count = ft_putptr_pf(va_arg(args, void *));
	else if (format == 'X')
		count = ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == 'c')
		count = ft_putchar_pf(va_arg(args, int));
	else
	{
		ft_putchar_pf('%');
		count = ft_putchar_pf(format);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_format(*format, args);
		}
		else
			count += ft_putchar_pf(*format);
		format++;
	}
	va_end(args);
	return (count);
}
