/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:23:58 by yachan            #+#    #+#             */
/*   Updated: 2024/07/07 19:24:01 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchr(int c)
{
	char	chr;

	chr = c;
	write(1, &chr, 1);
	return (1);
}
