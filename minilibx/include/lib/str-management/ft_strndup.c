/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:31:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/20 08:53:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*new;

	new = (char *)malloc(len + 1);
	if (new)
		ft_strlcpy(new, s, len + 1);
	return (new);
}

/*
#include <stdio.h>
#include "lib/libft.h"
int main ()
{
	char s1[] = "Hello@there"; // 5
	char s2[] = "Welcome"; // 7
	char *new;

	new = ft_strndup(s1, 5);
	printf("[%s]\n", new);
	free(new);

	new = ft_strndup(s2, 7);
	printf("[%s]\n", new);
	free(new);
}
*/