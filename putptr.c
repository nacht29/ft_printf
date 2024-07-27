/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:26:56 by yachan            #+#    #+#             */
/*   Updated: 2024/07/27 14:25:14 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_hex(uintptr_t num)
{
	char	*base;
	char	n;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ptr_hex(num / 16);
	n = base[num % 16];
	write(1, &n, 1);
	count++;
	return (count);
}

int	putptr(void *ptr)
{
	uintptr_t	out;

	if ((uintptr_t)ptr == 0)
	{
		write(1, NULL_POINTER, ft_strlen(NULL_POINTER));
		return ((int)(ft_strlen(NULL_POINTER)));
	}
	out = (uintptr_t)ptr;
	write(1, "0x", 2);
	return (ptr_hex(out) + 2);
}
