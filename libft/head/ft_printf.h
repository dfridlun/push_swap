/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:02:23 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/27 15:48:32 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_handle_format(const char format, va_list args);
int	ft_putstr_pf(const char *str);
int	ft_put_unsigned(unsigned int n);
int	ft_putchar_pf(char c);
int	ft_putnbr_pf(int n);
int	ft_putptr_pf(void *ptr);
int	ft_puthex(unsigned long n, int uppercase);

#endif 