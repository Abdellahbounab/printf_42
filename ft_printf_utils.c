/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:04:31 by abounab           #+#    #+#             */
/*   Updated: 2024/02/03 22:38:13 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char	*pointer)
{
	size_t	len;

	len = 0;
	if (pointer)
	{
		while (*(char *)pointer)
		{
			write(1, pointer, 1);
			pointer++;
			len++;
		}
	}
	else
		len += ft_putstr("(null)");
	return (len);
}

int	ft_ntoi(unsigned int number, char type)
{
	char	c;
	int		len;
	int		num;

	len = 0;
	num = (int)number;
	if ((type == 'd' || type == 'i') && num < 0)
	{
		len += write (1, "-", 1);
		len += ft_ntoi(num * -1, 'u');
	}
	else if (number > 9)
	{
		len += ft_ntoi((number / 10), 'u');
		len += ft_ntoi((number % 10), 'u');
	}
	else
	{
		c = '0' + number;
		len += write(1, &c, 1);
	}
	return (len);
}

int	ft_hexa(size_t number, char flag)
{
	char			*hexa;
	int				maj;
	int				len;
	char			c;
	unsigned int	num;

	maj = 0;
	len = 0;
	hexa = "0123456789abcdef";
	num = (unsigned int) number;
	if (flag == 'X')
		maj = -32;
	if (flag == 'X' || flag == 'x')
		number = num;
	if (number >= 16)
		len += ft_hexa((number / 16), flag);
	c = hexa[number % 16];
	if ((number % 16) >= 10)
		c += maj;
	len += write(1, &c, 1);
	return (len);
}

int	ft_hexapointer(void *pointer)
{
	int				len;
	size_t			transf;

	len = 0;
	transf = (size_t)pointer;
	len += ft_putstr("0x");
	if (pointer == NULL)
		return (write (1, "0", 1), ++len);
	len += ft_hexa(transf, 'p');
	return (len);
}
