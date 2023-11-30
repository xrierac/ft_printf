/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_xhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:09:33 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/30 10:37:17 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_dec_to_xhex(unsigned long n, char *base)
{
	char	*hex;
	char	coded;
	int		i;

	hex = malloc(25);
	if (hex == NULL)
		return (NULL);
	i = 0;
	if (n == 0)
		hex[i++] = '0';
	else
	{
		while (n != 0)
		{
			coded = base[n % 16];
			n = n / 16;
			hex[i] = coded;
			i++;
		}
	}
	hex[i++] = 'x';
	hex[i++] = '0';
	hex[i] = '\0';
	return (ft_strrev(hex));
}
