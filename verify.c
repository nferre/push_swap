/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:57:57 by nferre            #+#    #+#             */
/*   Updated: 2021/11/18 14:28:20 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	verify_params(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (++j != argc)
	{
		i = -1;
		while (argv[j][++i])
		{		
			if (argv[j][i] == '-' && (argv[j][i + 1] >= 48 &&
				argv[j][i + 1] <= 57))
				continue ;
			else if (argv[j][i] < 48 || argv[j][i] > 57)
			{
				write(1, "Error\n", 6);
				return (-1);
			}
		}
	}
	return (0);
}

int	verify_char(char **argv)
{
	int	i;

	i = -1;
	while (argv[1][++i])
	{
		if (argv[1][i] != ' ' && argv[1][i] != '-' &&
			(argv[1][i] < '0' || argv[1][i] > '9'))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
	}
	i = -1;
	return (0);
}

void	check_if_empty(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while (argv[1][++i])
			if (argv[1][i] != ' ')
				return ;
	}
	else
		return ;
	exit(0);
}
