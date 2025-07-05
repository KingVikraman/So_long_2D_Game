/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:09:37 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:09:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
dynamically allocates memory and sets allocated bytes to 0
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*holder;
	size_t	total_size;

	if ((size && (nmemb > UINT_MAX / size)) || (nmemb && (size > UINT_MAX
				/ nmemb)))
		return (NULL);
	total_size = nmemb * size;
	holder = malloc(total_size);
	if (!holder)
		return (NULL);
	ft_memset(holder, 0, total_size);
	return (holder);
}

/*
#include <stdio.h>
int main(void)
{
	// int *int_arr = ft_calloc(4, sizeof(int));
	// if (!int_arr)
	// 	return (0);
	char *str = ft_calloc(4, sizeof(char));
	// char *str = malloc(sizeof(char) * 4);
	// for (int i = 0; i < 4; i ++)
	// 	printf("str[%i]: %c\n", i, str[i]);
	// 	write(1, &str[i], 1);
	// printf("str[10]: %c\n", str[10]);
	write(1, "str: ", 5);
	write(1, str, 10);
}
*/