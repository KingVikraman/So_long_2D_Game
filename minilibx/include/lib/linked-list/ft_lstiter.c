/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:09:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:09:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*iterate through a linked list and 
apply function f() to the contents of each node
*return value: none
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		temp = current->next;
		f(current->content);
		current = temp;
	}
}
