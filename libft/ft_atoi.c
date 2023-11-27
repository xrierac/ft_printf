/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:29:52 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/07 15:24:31 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned long	i;
	int				sign;

	i = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		i = (i * 10) + (*nptr - '0');
		if (i > 9223372036854775807 && sign == 1)
			return (-1);
		else if (i > 9223372036854775807 && sign == -1)
			return (0);
		nptr++;
	}
	return ((int)(i * sign));
}
