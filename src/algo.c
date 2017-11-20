/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/20 13:13:35 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cpt_stars(t_struct *d)
{
	int i;
	int j;

	i = 0;
	d->nb_stars = 0;
	while (d->piece[i])
	{
		j = 0;
		while (d->piece[i][j])
		{
			if (d->piece[i][j] == '*')
				d->nb_stars++;
			j++;
		}
		i++;
	}
}

void	tamer(int i, int j)
{
	ft_putstr_fd("Rendu = \n", fd);
	ft_putnbr_fd(j, fd);
	ft_putstr_fd(" | ", fd);
	ft_putnbr_fd(i, fd);
}

int		place(t_struct *d, int i, int j)
{
	int miam;
	int a;
	int b;
	int stars;

	stars = 0;
	miam = 0;
	a = 0;
	while (a < d->piece_y_max)
	{
		b = 0;
		while (b < d->piece_x_max)
		{
			if (d->piece[a][b] == '*'
				&& i + a > 0 && j + b > 0
				&& i + a < d->y_max && j + b < d->x_max)
			{
				if (d->map[i + a][j + b] == 'X')
					return (1);
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		la_balade(t_struct *d)
{
	int i;
	int j;

	i = 0 - (d->piece_y_max - 1);
	while (i < d->y_max)
	{
		j = 0 - (d->piece_x_max - 1);
		while (j < d->x_max)
		{
			if (place(d, i, j) == 1)
			{
				print_result(i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
