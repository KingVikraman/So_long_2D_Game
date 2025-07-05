/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:08:49 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:49 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*traverses to end of linked list and add one node
*return value: none
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	end = ft_lstlast(*lst);
	end->next = new;
}
