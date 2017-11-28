/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/22 17:22:11 by jcoutare         ###   ########.fr       */
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
				&& (i + a) >= 0 && (j + b) >= 0
				&& (i + a) < d->y_max && (j + b) < d->x_max)
			{
				if (d->map[i + a][j + b] == d->gentil)
				{
					miam++;
					stars++;
				}
				else if (d->map[i + a][j + b] == '.')
					stars++;
			}
			b++;
		}
		a++;
	}
	if (miam == 1 && stars == d->nb_stars)
		return (1);
	/*	ft_putstr_fd("DATA : MIAM = ", fd);
	ft_putnbr_fd(miam, fd);
	ft_putstr_fd(" STARS = ", fd);
	ft_putnbr_fd(stars, fd);
	ft_putstr_fd(" / ", fd);
	ft_putnbr_fd(d->nb_stars, fd);
	ft_putstr_fd("| i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putstr_fd(" j = ", fd);
	ft_putnbr_fd(j, fd);
	ft_putchar_fd('\n', fd);
	*/return (0);
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
	  j++;
	}
      i++;  
    }
  choose_algo(d, re);
}

void	choose_algo(t_struct *d, int *re)
{
  if (d->pos1_X <= d->pos2_X)
    {
      if (d->pos1_Y <= d->pos2_Y)
	{
	  d->selec = 1;
	  c_tipar(d, re);
	  return ;
	}
      if (d->pos1_Y >= d->pos2_Y)
	{
	  d->selec = 2;
	  c_tipar(d, re);
	  return ;
	}
    }
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
void	c_tipar(t_struct *d, int *re)
{
  cpt_stars(d);
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
	      print_result(0,0);
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
	  print_result(0,0);
	}
    }
  if (d->selec == 2)
    {
      if (*re == 1)
	{
	  *re = 0;
	  if (la_promenade(d) == 1)
	    clear(d);
	  else
	    print_result(0,0);
	}
      else if (la_repromenade(d) == 1)
	{
	  clear(d);
	  *re = 1;
	}
      else
	print_result(0,0);
    }
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
	      print_result(0,0);
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
	  print_result(0,0);
	}
    }
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
	      print_result(0,0);
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
	  print_result(0,0);
	}
    }
}
