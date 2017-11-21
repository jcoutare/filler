/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:04:59 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/21 15:00:07 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	affiche(t_struct d)
{
	int stop = 0;
	if (d.map_filled == 1 && stop != 1)
    {
		int i = 0;
		ft_putstr_fd("\n[MAP]\n", fd);
		ft_putstr_fd("[Y = ", fd);
		ft_putnbr_fd(d.y_max, fd);
		ft_putstr_fd(" X = ", fd);
		ft_putnbr_fd(d.x_max, fd);
		ft_putstr_fd("]\n", fd);
		while (d.map[i])
		{
			ft_putstr_fd(d.map[i], fd);
			ft_putchar_fd('\n', fd);
			i++;
		}
		stop = 1;
    }
	if (d.piece_filled == 1)
    {
		int j = 0;
		ft_putstr_fd("\n[PIECE] ", fd);
		ft_putnbr_fd(d.piece_y_max, fd);
		ft_putstr_fd(" ", fd);
		ft_putnbr_fd(d.piece_x_max, fd);
		ft_putchar_fd('\n', fd);
		while (d.piece[j])
		{
			ft_putstr_fd(d.piece[j], fd);
			ft_putchar_fd('\n', fd);
			j++;
		}
    }
}

int		main(void)
{
	t_struct d;
	char *buf;
	int kk;
	int re;

	re = 0;
	buf = NULL;
	d.player = 0;
	d.y_max = 0;
	d.x_max = 0;
	d.map_filled = 0;
	d.piece_filled = 0;
	d.piece_x_max = 0;
	d.piece_y_max = 0;
	d.gentil = 'O';
	if ((fd = open("check", O_RDWR | O_CREAT, S_IRWXU)) < 0)
		return (-1);
	while ((kk = get_next_line(0, &buf)) > 0)
    {
		parse(&d, buf);
		if (d.piece_filled == 1)
		{
			cpt_stars(&d);
			//affiche(d);
			if (re == 1)
			{
				re = 0;
				if (la_rebalade(&d) == 1)
				{
					free_tab(d.map);
					free_tab(d.piece);
					d.y_max = 0;
					d.x_max = 0;
					d.piece_filled = 0;
					d.map_filled = 0;
				}
				else
				{
					print_result(0,0);
					return (0);
				}
			}
			else if (la_balade(&d) == 1)
			{
				free_tab(d.map);
				free_tab(d.piece);
				d.y_max = 0;
				d.x_max = 0;
				d.piece_filled = 0;
				d.map_filled = 0;
				re = 1;
			}
			else
			{
				print_result(0,0);
				return (0);
			}
		}
    }
	if (kk == -1)
		return (-1);
	close(fd);
	return (0);
}
