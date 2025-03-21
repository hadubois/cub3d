/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:38:25 by asritz            #+#    #+#             */
/*   Updated: 2024/01/30 17:15:53 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(int i, const char *format, va_list args)
{
	int	length;

	length = 0;
	if (format[i] == 'c')
		length += ft_putchar_fd_print(va_arg(args, int), 1);
	else if (format[i] == 's')
		length += ft_putstr_fd_print(va_arg(args, char *), 1);
	else if (format[i] == 'p')
		length += ft_putptr(va_arg(args, void *));
	else if (format[i] == 'd' || format[i] == 'i')
		length += ft_putnbr_fd_print(va_arg(args, int), 1);
	else if (format[i] == 'u')
		length += ft_putunbr_fd_print(va_arg(args, unsigned int), 1);
	else if (format[i] == 'x')
		length += ft_putlow_hexa(va_arg(args, unsigned int));
	else if (format[i] == 'X')
		length += ft_putupp_hexa(va_arg(args, unsigned int));
	else if (format[i] == '%')
		length += ft_putchar_fd_print('%', 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	va_start(args, format);
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			while (format[i] != '\0' && format[i] != '%')
			{
				length += ft_putchar_fd_print(format[i], 1);
				i++;
			}
		}
		else
		{
			length += ft_checkformat((i + 1), format, args);
			i = i + 2;
		}
	}
	va_end(args);
	return (length);
}
