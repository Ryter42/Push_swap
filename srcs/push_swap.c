/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:34 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/30 20:43:38 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int	main(int av, char **ac)
{
	t_list	*lista;
	t_list	*listb;
	t_data	*data;

	if (av < 2)
		return (0);
	if (init(av, ac, &data, &lista, &listb) == 0)
		return (0);
	algo(data, &lista, &listb);
	while (*(data->intnb))
	{
		printf("%d\n", *(data->intnb));
		data->intnb++;
	}
printf("mediane = %d\n", data->mediane);
	while (listb)
	{
		printf("%d\n", listb->value);
		listb = listb->next;
	}
return (0);
}
