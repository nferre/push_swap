/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:52:22 by nferre            #+#    #+#             */
/*   Updated: 2021/11/14 10:34:07 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	find_median500(int *tab, int size, t_list *a)
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
	a->qn = malloc(sizeof(int) * 12);
	while (++j != 12)
	{
		a->qn[j] = tab[(size / 13) * (j + 1)];
	}
	a->size_tab = j;
}

int	get_min(t_list *a)
{
	int	i;
	int	pos;
	int	temp;

	i = -1;
	pos = 0;
	temp = 2147483647;
	while (++i != a->size)
	{
		if (a->tab[i] < temp)
		{
			pos = i;
			temp = a->tab[i];
		}
	}
	return (temp);
}

int	get_max(t_list *a)
{
	int	i;
	int	pos;
	int	temp;

	i = -1;
	pos = 0;
	temp = -2147483648;
	while (++i != a->size)
	{
		if (a->tab[i] > temp)
		{
			pos = i;
			temp = a->tab[i];
		}
	}
	return (temp);
}

int	get_pos_max(t_list *a)
{
	int	i;
	int	pos;
	int	temp;

	i = -1;
	pos = 0;
	temp = -2147483648;
	while (++i != a->size)
	{
		if (a->tab[i] > temp)
		{
			pos = i;
			temp = a->tab[i];
		}
	}
	return (pos);
}

int	get_pos_min(t_list *a)
{
	int	i;
	int	pos;
	int	temp;

	i = -1;
	pos = 0;
	temp = 2147483647;
	while (++i != a->size)
	{
		if (a->tab[i] < temp)
		{
			pos = i;
			temp = a->tab[i];
		}
	}
	return (pos);
}
