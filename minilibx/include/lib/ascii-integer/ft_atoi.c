/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:04:36 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/12 22:07:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
converts string to integer
accept whitespaces and 1 sign (+) (-) before digits
*/
int	ft_atoi(const char *nptr)
{
	int	op;
	int	results;

	op = 1;
	results = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			op *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		results = results * 10 + (*nptr - '0');
		nptr++;
	}
	return (results * op);
}
