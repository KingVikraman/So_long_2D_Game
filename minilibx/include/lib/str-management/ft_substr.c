/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:45 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:11:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*holder;
	size_t	i;
	size_t	strt;

	if (!s)
		return (NULL);
	strt = (size_t)start;
	if (strt > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - strt + 1))
		holder = malloc(ft_strlen(s) - strt + 2);
	else
		holder = malloc(len + 1);
	if (!holder)
		return (NULL);
	i = 0;
	while (i < len && s[strt + i] != '\0')
	{
		holder[i] = s[strt + i];
		i++;
	}
	holder[len] = '\0';
	return (holder);
}
