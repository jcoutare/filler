/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:52:16 by jcoutare          #+#    #+#             */
/*   Updated: 2017/12/26 17:07:20 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_pos(t_struct *d, int i, int j)
{
	if (d->map[i][j] == d->gentil)
	{
		d->pos1_x = i;
		d->pos1_y = j;
	}
	if (d->map[i][j] != '.' && d->map[i][j] != d->gentil)
	{
		d->pos2_x = i;
		d->pos2_y = j;
	}
}

void	get_pos(t_struct *d, int *re)
{
	int i;
	int j;

	i = 0;
	d->pos1_x = 0;
	d->pos1_y = 0;
	d->pos2_x = 0;
	d->pos2_y = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			set_pos(d, i, j);
			j++;
		}
		i++;
	}
	choose_algo(d, re);
}

int		test_pos(t_struct *d, int *re)
{
	if (d->pos1_x <= d->pos2_y)
	{
		if (d->pos1_x <= d->pos2_y)
		{
			d->selec = 1;
			c_tipar(d, re);
			return (1);
		}
		if (d->pos1_y >= d->pos2_y)
		{
			d->selec = 2;
			c_tipar(d, re);
			return (1);
		}
	}
	return (0);
}

void	choose_algo(t_struct *d, int *re)
{
	if (test_pos(d, re) == 1)
		return ;
	if (d->pos1_x >= d->pos2_x)
	{
		if (d->pos1_y <= d->pos2_y)
		{
			d->selec = 3;
			c_tipar(d, re);
			return ;
		}
		if (d->pos1_y >= d->pos2_y)
		{
			d->selec = 4;
			c_tipar(d, re);
			return ;
		}
	}
	c_tipar(d, re);
}
