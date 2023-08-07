/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:05:52 by nferre            #+#    #+#             */
/*   Updated: 2021/11/14 10:37:25 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_list *a)
{
	int	i;

	i = 0;
	while (++i != a->size)
		if (a->tab[i - 1] < a->tab[i])
			return (-1);
	return (0);
}

void	verif(int numb, int temp)
{
	if (temp > numb)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	verif_other(int numb, int temp, int sign)
{
	if (temp > numb && numb != -2147483648 && sign < 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	verif_atoi(const char *str, int i, int *sign)
{	
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		*sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	numb;
	int	temp;

	if (!str)
		return (0);
	numb = 0;
	temp = 0;
	i = 0;
	sign = 1;
	i = verif_atoi(str, i, &sign);
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = numb * 10 + (str[i] - '0');
		if (sign < 0)
			verif_other(numb, temp, sign);
		else
			verif(numb, temp);
		temp = numb;
		i++;
	}
	return (numb * sign);
}
