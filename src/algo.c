/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/21 11:59:12 by jcoutare         ###   ########.fr       */
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

int	cpt_dot(t_struct *d)
{
	int i;
	int j;
	int nb_dot;

	i = 0;
	nb_dot = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == '.')
				nb_dot++;
			j++;
		}
		i++;
	}
	return (nb_dot);
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
				&& i + a >= 0 && j + b >= 0
				&& i + a < d->y_max && j + b < d->x_max)
			{
				if (d->map[i + a][j + b] == 'X')
				{
					miam++;
					stars++;
				}
				else if (d->map[i + a][j + b] == '.')
					stars++;
				else
					return (0);
			}
			b++;
		}
		a++;
	}
	if (miam == 1 && stars == d->nb_stars)
		return (1);
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
				print_result_fd(i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
