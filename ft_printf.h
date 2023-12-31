/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:06:23 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/30 10:31:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*ft_dec_to_hex(unsigned int n, char *base);
char	*ft_dec_to_xhex(unsigned long n, char *base);
char	*ft_utoa(unsigned int n);
int		in_set(char c, char const *set);
#endif
