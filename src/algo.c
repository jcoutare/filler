/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/17 15:13:17 by jcoutare         ###   ########.fr       */
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

int	algo(t_struct *d)
{
	int miam;
	int ok;
	int i;
	int j;
	int a;
	int b;

	i = 0;
	a = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			a = 0;
			ok = 0;
			miam = 0;
			while (d->piece[a])
			{
				b = 0;

				while (d->piece[a][b])
				{
					if (d->piece[a][b] == '*' && ((i + a < d->y_max) && j + b < d->x_max))
					{
						if (d->map[i + a][j + b] == '.')
							ok++;
						if (d->map[i + a][j + b] == '*')
						{
							ok++;
							miam++;
						}
						if (ok == d->nb_stars && miam == 1)
						{
							print_result(j, i);
							return (1);
						}
					}
					b++;
				}

				a++;
			}

			j++;
		}
		i++;
	}
	return (0);
}

