/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:39 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:11:39 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	in_set(char c, char const *set);

/*
*trims away delimiters on both sides of a str
*multiple delimiters is accepted
*delimiters in the middle of the min str is ignored
*return value: trimmed str
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (in_set(s1[start], set) == TRUE)
	{
		if (start == end)
			return (ft_strdup(""));
		start++;
	}
	while (in_set(s1[end], set) == TRUE)
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (TRUE);
		set++;
	}
	return (FALSE);
}
