/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:08:11 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:11 by jpaul            ###   ########.fr       */
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
