/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:09:33 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/30 10:43:06 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_dec_to_hex(unsigned int n, char *base)
{
	char	*hex;
	char	coded;
	int		i;

	hex = malloc(20);
	if (hex == NULL)
		return (NULL);
	if (n == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	i = 0;
	while (n != 0)
	{
		coded = base[n % 16];
		n = n / 16;
		hex[i] = coded;
		i++;
	}
	hex[i] = '\0';
	return (ft_strrev(hex));
}
