/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:34 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/16 01:48:19 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstfree(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	datafree(t_data *data)
{
	int	i;

	i = 0;
	if (data->intnb)
		free(data->intnb);
	while (data->charnb[i])
	{
		free(data->charnb[i]);
		i++;
	}
	free(data->charnb);
	free(data);
}

void ft_free(t_data *data, t_list *lsta, t_list *lstb)
{
	if (data)
		datafree(data);
	if (lsta)
		lstfree(lsta);
	if (lstb)
		lstfree(lstb);
}

int	checklst(t_list *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int av, char **ac)
{
	t_list	*lista;
	t_list	*listb;
	t_data	*data;

	if (av < 2)
		return (0);
	if (init(av, ac, &data, &lista, &listb) == 0)
		return (write(1, "error\n", 6), 0);
	if (checklst(lista) == 1)
		return (0);
	algo(data, &lista, &listb);
	ft_free(data, lista, listb);
	// while (lista)
	// {
	// 	printf("%d\n", lista->value);
	// 	lista = lista->next;
	// }	
// 	while (*(data->intnb))
// 	{
// 		printf("%d\n", *(data->intnb));
// 		data->intnb++;
// 	}
// printf("mediane = %d\n", data->mediane);
// 	while (listb)
// 	{
// 		printf("%d\n", listb->value);
// 		listb = listb->next;
// 	}
// 	//test des fonctions de mouvement
// 	printf("\n\n\ntest des fonctions de mouvement\n\n\n");
// 	// t_list *lst;
// 	t_list *lst1;
// 	t_list *lst2;
// 	t_list *lst3;

// 	lst1 = malloc(sizeof(t_list));
// 	lst2 = malloc(sizeof(t_list));
// 	lst3 = malloc(sizeof(t_list));

// 	lst1->value = 1;
// 	lst2->value = 2;
// 	lst3->value = 3;

// 	lst1->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = NULL;
// 	rrr(&lst1, &lst1);
// 	// printf("%d\n", lst->value);
// 	while (lst1)
// 	{
// 		printf("%d\n", lst1->value);
// 		lst1 = lst1->next;
// 	}
return (0);
}