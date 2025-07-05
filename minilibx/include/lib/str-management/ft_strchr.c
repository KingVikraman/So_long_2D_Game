/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:10:11 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:10:11 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*locates the (first occurence) of char in a str
*return value: a substr starting from the (first occurence) of char 
|| NULL if char is not found
*/
char	*ft_strchr(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == ref)
			return (temp);
		temp++;
	}
	if (c == '\0')
		return (temp);
	return (NULL);
}
