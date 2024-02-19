/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:12:01 by abounab           #+#    #+#             */
/*   Updated: 2024/02/03 22:35:28 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

size_t	ft_print_base(char flag, va_list args);

int		ft_hexa(size_t number, char flag);

int		ft_hexapointer(void *pointer);

int		ft_ntoi(unsigned int number, char type);

int		ft_putstr(char	*pointer);

#endif