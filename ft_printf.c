/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:18:59 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/27 16:44:43 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	in_set(char c, const char *set)
{
	if (c == '\0')
		return (0);
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

size_t	print_conversion(char *str, va_list ap)
{
	size_t	len;

	len = 0;

}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			len;
	char			*buffer;

	len = 0;
	va_start(ap, format);
	if (!format || !*format)
		return (-1);
	while (format[len])
	{
		if (format[len] == '%')
		{
			len = len + print_conversion(&format[len], ap);
		}
		else
		{
			ft_putchar_fd(format[len], 1);
			len++;
		}
	}
	va_close(ap);
	return (len);
}
