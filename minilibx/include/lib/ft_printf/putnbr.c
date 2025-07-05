/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:08:06 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:06 by jpaul            ###   ########.fr       */
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
