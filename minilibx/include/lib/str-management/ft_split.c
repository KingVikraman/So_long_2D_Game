/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:10:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:10:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	alloc_len(char const *s, char c);
static void		split(char const *s, char c, char ***str_arr, size_t itr);

/*
*splits str according to delimiter and store the splitted substr in an array
*return value: array of substr
*/
char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**str_arr;

	if (!s)
		return (NULL);
	len = alloc_len(s, c);
	str_arr = malloc((len + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	split(s, c, &str_arr, len);
	str_arr[len] = NULL;
	return (str_arr);
}

static size_t	alloc_len(char const *s, char c)
{
	size_t	len;
	int		flag;

	len = 0;
	flag = 1;
	while (*s)
	{
		if (*s != c && flag == 1)
		{
			len++;
			flag = 0;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	return (len);
}

static void	split(char const *s, char c, char ***str_arr, size_t itr)
{
	size_t	start;
	size_t	end;
	size_t	arr_pos;

	start = 0;
	arr_pos = 0;
	while (itr > 0)
	{
		end = 0;
		while (s[start] == c)
			start++;
		while (s[start + end] != c && s[start + end] != '\0')
			end++;
		(*str_arr)[arr_pos] = ft_substr(s, (int)start, end);
		start = start + end;
		arr_pos++;
		itr--;
	}
}
