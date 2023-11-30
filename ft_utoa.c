/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:15:57 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/30 10:37:49 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(15);
	if (!str)
		return (NULL);
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
