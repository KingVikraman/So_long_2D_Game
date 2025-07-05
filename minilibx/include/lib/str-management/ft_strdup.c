/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:10:15 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:10:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*allocates memory and duplicate a str
*return value: duplicated str
*/
char	*ft_strdup(const char *src)
{
	int		i;
	char	*holder;

	i = 0;
	holder = malloc(ft_strlen(src) + 1);
	if (!holder)
		return (NULL);
	while (src[i])
	{
		holder[i] = src[i];
		i++;
	}
	holder[i] = '\0';
	return (holder);
}
