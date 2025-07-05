/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:35 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:11:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*locates the (last occurence) of char in a str
*return value: a substr startting from the (last occurence) of char
|| NULL if char is not found
*/
char	*ft_strrchr(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
		temp++;
	while (temp != s)
	{
		if (*temp == ref)
			break ;
		temp--;
	}
	if (temp == s && *temp != ref)
		return (NULL);
	return (temp);
}
