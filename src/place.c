/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:46:14 by jcoutare          #+#    #+#             */
/*   Updated: 2017/12/26 16:50:05 by jcoutare         ###   ########.fr       */
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

void	clear(t_struct *d)
{
	free_tab(d->map);
	free_tab(d->piece);
	d->y_max = 0;
	d->x_max = 0;
	d->piece_filled = 0;
	d->map_filled = 0;
}

void	test_place(t_struct *d, t_nul *lol, int i, int j)
{
	if (d->piece[lol->a][lol->b] == '*'
		&& (i + lol->a) >= 0 && (j + lol->b) >= 0
		&& (i + lol->a) < d->y_max && (j + lol->b) < d->x_max)
	{
		if (d->map[i + lol->a][j + lol->b] == d->gentil)
		{
			lol->miam++;
			lol->stars++;
		}
		else if (d->map[i + lol->a][j + lol->b] == '.')
			lol->stars++;
	}
}

int		place(t_struct *d, int i, int j)
{
	t_nul lol;

	lol.stars = 0;
	lol.miam = 0;
	lol.a = 0;
	while (lol.a < d->piece_y_max)
	{
		lol.b = 0;
		while (lol.b < d->piece_x_max)
		{
			test_place(d, &lol, i, j);
			lol.b++;
		}
		lol.a++;
	}
	if (lol.miam == 1 && lol.stars == d->nb_stars)
		return (1);
	return (0);
}
