/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:30 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:11:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*locates a substr (needle) in a main str (haystack)
*return value: substr if located || NULL if substr is not located
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	len = ft_strlen(needle);
	if (n == 0 && haystack == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len <= n)
	{
		if (ft_strncmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		n--;
		haystack++;
	}
	return (NULL);
}
