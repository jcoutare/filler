/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/12/26 16:53:17 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
