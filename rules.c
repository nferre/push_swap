/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:17:22 by nferre            #+#    #+#             */
/*   Updated: 2021/11/11 17:31:26 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_list *list, int i)
{
	int	temp;

	if (list->size < 2)
		return ;
	temp = list->tab[list->size - 1];
	list->tab[list->size - 1] = list->tab[list->size - 2];
	list->tab[list->size - 2] = temp;
	if (i == 0)
		write(1, &"sa\n", 3);
	else
		write(1, &"sb\n", 3);
}

void	push(t_list *a, t_list *b, int i)
{
	if (a->size == 0)
		return ;
	b->tab[b->size] = a->tab[a->size - 1];
	a->tab[a->size - 1] = 0;
	a->size--;
	b->size++;
	if (i == 0)
		write(1, &"pa\n", 3);
	else
		write(1, &"pb\n", 3);
}

void	rotate(t_list *a, int j)
{
	int	temp;
	int	temp2;
	int	i;

	if (a->size == 1 || a->size == 0)
		return ;
	i = -1;
	temp2 = a->tab[a->size - 1];
	while (i++ < a->size - 1)
	{
		temp = a->tab[i];
		a->tab[i] = temp2;
		temp2 = temp;
	}
	if (j == 0)
		write(1, &"ra\n", 3);
	else
		write(1, &"rb\n", 3);
}

void	r_rotate(t_list *a, int j)
{
	int	i;
	int	temp;
	int	temp2;

	i = a->size;
	temp2 = a->tab[0];
	while (i-- != 0)
	{
		temp = a->tab[i];
		a->tab[i] = temp2;
		temp2 = temp;
	}
	if (j == 0)
		write(1, &"rra\n", 4);
	else
		write(1, &"rrb\n", 4);
}

void	push_last(t_list *a, t_list *b)
{
	while (a->size != 0)
		push(a, b, 1);
}
