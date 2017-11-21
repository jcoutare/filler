/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:23:32 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/21 15:31:24 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		la_repromenade(t_struct *d)
{
	int i;
	int j;

	i = d->y_max;
	while (i >= d->piece_y_max - 1)
	{
		j = 0 - (d->piece_x_max - 1);
		while (j <= d->x_max)
		{
			if (place(d, i, j) == 1)
			{
				print_result(i, j);
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int		la_promenade(t_struct *d)
{
	int i;
	int j;

	i = 0 - (d->piece_y_max - 1);
	while (i <= d->y_max)
	{
		j = d->x_max;
		while (j >= d->piece_x_max - 1)
		{
			if (place(d, i, j) == 1)
			{
				print_result(i, j);
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}
