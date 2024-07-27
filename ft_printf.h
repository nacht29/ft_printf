/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:59:23 by yachan            #+#    #+#             */
/*   Updated: 2024/07/27 14:22:48 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

# ifdef __APPLE__
#  define NULL_STR "(null)"
#  define NULL_POINTER "0x0"
# elif __linux__
#  define NULL_STR ""
#  define NULL_POINTER "(nil)"
# else
#  error "Unsupported operating system"
# endif

size_t	ft_strlen(const char *s);
int		putchr(int c);
int		putstr(const char *s);
int		putptr(void *ptr);
int		putnbr(int n);
int		put_uint(unsigned int n);
int		puthex(unsigned int num, char hex);
int		ft_printf(const char *c, ...);
#endif
