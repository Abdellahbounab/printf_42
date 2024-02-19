/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:12:55 by abounab           #+#    #+#             */
/*   Updated: 2024/02/03 22:48:31 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_base(char flag, va_list args)
{
	size_t			len;
	unsigned char	one_char;

	len = 0;
	if (flag == 'c')
	{
		one_char = (unsigned char)va_arg(args, int);
		len += write (1, &one_char, 1);
	}
	else if (flag == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (flag == 'd' || flag == 'i')
		len += ft_ntoi(va_arg(args, int), 'd');
	else if (flag == 'u')
		len += ft_ntoi(va_arg(args, unsigned int), 'u');
	else if (flag == 'x' || flag == 'X')
		len += ft_hexa(va_arg(args, int), flag);
	else if (flag == '%')
		len += write(1, "%%", 1);
	else if (flag == 'p')
		len += ft_hexapointer(va_arg(args, void *));
	else
		len += write(1, &flag, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	if (write(1, 0, 0) != -1)
	{
		va_start(args, format);
		while (*format)
		{
			if (*format != '%')
				len += write (1, format, 1);
			else if ((*(format + 1)))
				len += ft_print_base(*(char *)++format, args);
			format++;
		}
		va_end(args);
		return (len);
	}
	return (-1);
}
