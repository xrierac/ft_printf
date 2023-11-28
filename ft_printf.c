/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:18:59 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/28 17:53:21 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_to_str(int c)
{
	char	*s;

	s = malloc(2);
	if (s == NULL)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

static int	putchr(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

char	*get_conversion(char c, va_list ap)
{
	if (c == 'c')
		return (ft_char_to_str(va_arg(ap, int)));
	if (c == 's')
		return (ft_strdup(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_dec_to_xhex(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'd')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'u')
		return (ft_utoa(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_dec_to_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_dec_to_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_strdup("%"));
	return (NULL);
}

int	print_chrs(const char *format, va_list ap, int len)
{
	int		size;
	int		i;
	char	*buffer;

	size = 0;
	while (format[++len])
	{
		if (format[len] == '%' && format[len + 1] != '\0')
		{
			i = 0;
			buffer = get_conversion(format[++len], ap);
			if (buffer == NULL)
				size += write(1, "(null)", 6);
			else
				while (buffer[i])
					size += putchr(buffer[i++]);
			free(buffer);
		}
		else
			size += putchr(format[len]);
		if (size == -1)
			break ;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				len;
	int				bytes;

	len = -1;
	va_start(ap, format);
	if (!format)
		return (-1);
	bytes = print_chrs(format, ap, len);
	va_end(ap);
	return (bytes);
}
