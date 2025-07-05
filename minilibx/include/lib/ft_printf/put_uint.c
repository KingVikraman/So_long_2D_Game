/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:07:52 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:07:52 by jpaul            ###   ########.fr       */
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
