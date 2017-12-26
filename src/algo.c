/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/12/26 16:46:28 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_pos(t_struct *d, int i, int j)
{
	if (d->map[i][j] == d->gentil)
	{
		d->pos1_X = i;
		d->pos1_Y = j;
	}
	if (d->map[i][j] != '.' && d->map[i][j] != d->gentil)
	{
		d->pos2_X = i;
		d->pos2_Y = j;
	}
}

void	get_pos(t_struct *d, int *re)
{
	int i;
	int j;

	i = 0;
	d->pos1_X = 0;
	d->pos1_Y = 0;
	d->pos2_X = 0;
	d->pos2_Y = 0;
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

int	test_pos(t_struct *d, int *re)
{
	if (d->pos1_X <= d->pos2_X)
	{
		if (d->pos1_Y <= d->pos2_Y)
		{
			d->selec = 1;
			c_tipar(d, re);
			return (1);
		}
		if (d->pos1_Y >= d->pos2_Y)
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
	if (d->pos1_X >= d->pos2_X)
	{
		if (d->pos1_Y <= d->pos2_Y)
		{
			d->selec = 3;
			c_tipar(d, re);
			return ;
		}
		if (d->pos1_Y >= d->pos2_Y)
		{
			d->selec = 4;
			c_tipar(d, re);
			return ;
		}
	}
	c_tipar(d, re);
}

void	algo_un(t_struct *d, int *re)
{
	if (d->selec == 1)
	{
		if (*re == 1)
		{
			*re = 0;
			if (la_balade(d) == 1)
				clear(d);
			else
			{
				clear(d);
				print_result(0, 0);
			}
		}
		else if (la_rebalade(d) == 1)
		{
			clear(d);
			*re = 1;
		}
		else
		{
			clear(d);
			print_result(0, 0);
		}
	}
}

void	algo_deux(t_struct *d, int *re)
{
	if (d->selec == 2)
	{
		if (*re == 1)
		{
			*re = 0;
			if (la_promenade(d) == 1)
				clear(d);
			else
				print_result(0, 0);
		}
		else if (la_repromenade(d) == 1)
		{
			clear(d);
			*re = 1;
		}
		else
			print_result(0, 0);
	}
}

void	algo_trois(t_struct *d, int *re)
{
	if (d->selec == 3)
	{
		if (*re == 1)
		{
			*re = 0;
			if (la_repromenade(d) == 1)
				clear(d);
			else
			{
				clear(d);
				print_result(0, 0);
			}
		}
		else if (la_promenade(d) == 1)
		{
			clear(d);
			*re = 1;
		}
		else
		{
			clear(d);
			print_result(0, 0);
		}
	}
}

void	algo_quatre(t_struct *d, int *re)
{
	if (d->selec == 4)
	{
		if (*re == 1)
		{
			*re = 0;
			if (la_rebalade(d) == 1)
				clear(d);
			else
			{
				clear(d);
				print_result(0, 0);
			}
		}
		else if (la_balade(d) == 1)
		{
			clear(d);
			*re = 1;
		}
		else
		{
			clear(d);
			print_result(0, 0);
		}
	}
}

void	c_tipar(t_struct *d, int *re)
{
	cpt_stars(d);
	algo_un(d, re);
	algo_deux(d, re);
	algo_trois(d, re);
	algo_quatre(d, re);
}
