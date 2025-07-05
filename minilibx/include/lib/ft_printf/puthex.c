/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:08:01 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex(unsigned int num, char hex)
{
	char	*base_cap;
	char	*base_low;
	long	lnum;
	char	n;
	int		count;

	base_cap = "0123456789ABCDEF";
	base_low = "0123456789abcdef";
	lnum = num;
	count = 0;
	if (lnum >= 16)
		count += puthex(lnum / 16, hex);
	if (hex == 'x')
		n = base_low[lnum % 16];
	else if (hex == 'X')
		n = base_cap[lnum % 16];
	write(1, &n, 1);
	count++;
	return (count);
}
