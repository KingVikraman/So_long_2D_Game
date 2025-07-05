/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:08:17 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:17 by jpaul            ###   ########.fr       */
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
