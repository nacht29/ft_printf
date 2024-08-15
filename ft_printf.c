/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:21:38 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:38:04 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	valid_form_spec(const char *c)
{
	int		i;
	int		j;
	char	*form_spec;

	i = 0;
	form_spec = "cspdiuxX%%";
	while (c[i])
	{
		if (c[i] == '%')
		{
			j = 0;
			while (form_spec[j] && form_spec[j] != c[i + 1])
			{
				if (!form_spec[j])
				{
					putstr("Invalid specifier\n");
					return (FALSE);
				}
				j++;
			}
		}
		i++;
	}
	return (TRUE);
}

static int	process_format(const char *c, int *i, va_list arg)
{
	int	count;

	count = 0;
	if (c[*i + 1] == 'c')
		count += putchr(va_arg(arg, int));
	else if (c[*i + 1] == 's')
		count += putstr(va_arg(arg, const char *));
	else if (c[*i + 1] == 'p')
		count += putptr(va_arg(arg, void *));
	else if (c[*i + 1] == 'd' || c[*i + 1] == 'i')
		count += putnbr(va_arg(arg, int));
	else if (c[*i + 1] == 'u')
		count += put_uint(va_arg(arg, unsigned int));
	else if (c[*i + 1] == 'x')
		count += puthex(va_arg(arg, int), 'x');
	else if (c[*i + 1] == 'X')
		count += puthex(va_arg(arg, int), 'X');
	else if (c[*i + 1] == '%')
		count += putchr('%');
	(*i)++;
	return (count);
}

int	ft_printf(const char *c, ...)
{
	va_list	arg;
	int		i;
	int		count;

	if (valid_form_spec(c) == FALSE)
		return (0);
	i = 0;
	count = 0;
	va_start(arg, c);
	while (c[i])
	{
		if (c[i] == '%')
			count += process_format(c, &i, arg);
		else
		{
			write(1, &c[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
