/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:06:43 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/30 20:36:34 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}


// void	ft_lstadd_front(t_list **l2, t_list **l1)
// {
// 	// tpm pour save l2
// 	t_list	**tmp;

	
// 	tmp = l2;
// 	// ecraser l2 avec son nv front (l1)
// 	(*l2) = (*l1);
// 	// du coup redonner la suite de l2 au nouveau l2
// 	(*l2)->next = *tmp;
// }
