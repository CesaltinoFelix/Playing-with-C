/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:11 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/06 15:08:09 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		t_abs(int x);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long int n);
int		ft_print_ptr(void *ptr);
int		ft_printf(const char *s, ...);
int		ft_putunsigned(unsigned int n);
int		ft_print_hex(unsigned long n, int type);
size_t	ft_strlen(const char *str);

#endif
