#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags {
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int	ft_printf(const char *format, ...);
#endif
