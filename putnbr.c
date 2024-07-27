/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:24:52 by yachan            #+#    #+#             */
/*   Updated: 2024/07/27 14:25:04 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(int n)
{
	char	num;
	long	lnum;
	int		count;

	lnum = n;
	count = 0;
	if (lnum < 0)
	{
		lnum *= -1;
		write(1, "-", 1);
		count++;
	}
	if (lnum >= 10)
		count += putnbr(lnum / 10);
	count++;
	num = '0' + lnum % 10;
	write(1, &num, 1);
	return (count);
}
