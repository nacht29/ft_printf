/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:27:12 by yachan            #+#    #+#             */
/*   Updated: 2024/07/27 14:25:22 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(const char *s)
{
	if (!s)
	{
		write(1, NULL_STR, ft_strlen(NULL_STR));
		return (ft_strlen(NULL_STR));
	}
	write(1, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}
