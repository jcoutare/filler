/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:00:48 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/21 13:59:40 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		la_rebalade(t_struct *d)
{
	int i;
	int j;

	i = d->y_max;

	while (i > d->piece_y_max - 1)
	{
		j = d->x_max;
		while (j > d->piece_x_max - 1)
		{
			if (place(d, i, j) == 1)
			{
				print_result(i, j);
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}
