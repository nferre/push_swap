/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:37:26 by nferre            #+#    #+#             */
/*   Updated: 2021/11/14 10:32:46 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	find_median(int *tab, int size, t_list *a)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (++i != size)
	{
		if (tab[i - 1] > tab[i])
		{
			ft_swap(&tab[i - 1], &tab[i]);
			i = 0;
		}
	}
	a->qn = malloc(sizeof(int) * 4);
	while (++j != 4)
	{
		a->qn[j] = tab[(size / 5) * (j + 1)];
	}
	a->size_tab = j;
}
