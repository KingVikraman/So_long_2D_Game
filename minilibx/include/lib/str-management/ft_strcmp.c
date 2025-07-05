/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/04 15:04:22 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>
void test_ft_strcmp(const char *s1, const char *s2)
{
    int result = ft_strcmp(s1, s2);
    int expected = strcmp(s1, s2);

    printf("ft_strcmp(\"%s\", \"%s\") = %d | strcmp = %d | %s\n",
           s1, s2, result, expected
		   , (result == expected) ? "✅ Passed" : "❌ Failed");
}

int main()
{
    test_ft_strcmp("hello", "hello"); 
    test_ft_strcmp("apple", "banana");
    test_ft_strcmp("banana", "apple");
    test_ft_strcmp("hello", "hello world");
    test_ft_strcmp("hello world", "hello");
    test_ft_strcmp("testa", "testb");
    test_ft_strcmp("testb", "testa");
    test_ft_strcmp("", "");
    test_ft_strcmp("", "hello");
    test_ft_strcmp("hello", "");
    test_ft_strcmp("Hello", "hello");
    test_ft_strcmp("\200", "\0");
    test_ft_strcmp("\200", "\177");
}
*/