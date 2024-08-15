/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:23:34 by yachan            #+#    #+#             */
/*   Updated: 2024/07/27 14:24:09 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_uint(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n >= 10)
		count += putnbr(n / 10);
	num = '0' + n % 10;
	write(1, &num, 1);
	count++;
	return (count);
}
