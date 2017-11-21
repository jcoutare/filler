/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:00:48 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/21 16:20:49 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		la_rebalade(t_struct *d)
{
	int i;
	int j;

	i = d->y_max;
	while (i >= d->piece_y_max - 1)
	{
		j = d->x_max;
		while (j >= d->piece_x_max - 1)
		{
			if (place(d, i, j) == 1)
			{
				print_result_fd(i, j);
				print_result(i, j);
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
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

void	c_tipar(t_struct *d)
{
	int re;

	re = 0;
	cpt_stars(d);
	if (re == 1)
	{
	re = 0;
	if (la_rebalade(d) == 1)
	clear(d);
	else
	print_result(0,0);
	}
	else if (la_balade(d) == 1)
	{
	clear(d);
	re = 1;
	}
	else
	print_result(0,0);
/*
	if (re == 1)
	{
		re = 0;
		if (la_repromenade(d) == 1)
			clear(d);
		else
			print_result(0,0);

	}
	else if (la_promenade(d) == 1)
	{
		clear(d);
		re = 1;
	}
	else
		print_result(0,0);
*/}
