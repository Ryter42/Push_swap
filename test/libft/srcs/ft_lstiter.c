/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:57:04 by emoreau           #+#    #+#             */
/*   Updated: 2022/12/02 20:00:46 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// void	plus3(void *i)
// {
// 	int *p = (int *)i;
// 	*p += 3;
// }

// int	main(void)
// {
// 	t_list *elem1;
// 	t_list *elem2;
// 	t_list *elem3;

// 	elem1 = malloc(sizeof(t_list));
// 	elem2 = malloc(sizeof(t_list));
// 	elem3 = malloc(sizeof(t_list));

// 	int a = 1;
// 	int b = 2;
// 	int c = 3;

// 	elem1->content = &a;
// 	elem2->content = &b;
// 	elem3->content = &c;

// 	elem1->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = NULL;
// 	ft_lstiter(elem1, plus3);
// 	printf("%d\n", *(int*)(elem1->content));
// 	while (elem1->next)
// 	{
// 		elem1 = elem1->next;
// 	printf("%d\n", *(int*)(elem1->content));
// 	}
// 	return (0);
// }