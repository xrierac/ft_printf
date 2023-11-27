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

int	ft_printf(const char *format, ...)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (in_set(*format, "-.# +0123456789"))
		//		DO SOMETHING;
			if (in_set(*format, "cspdiuxX%"))
		//		DO SOMETHING;
		}
	}
}
