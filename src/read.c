/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:04:59 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/22 13:34:15 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
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
  d.selec = 0;
  while ((kk = get_next_line(0, &buf)) > 0)
    {
      parse(&d, buf);
	  free(buf);
      if (d.piece_filled == 1)
	{
	  if (d.selec == 0)
	    get_pos(&d, &re);
	  else
	    c_tipar(&d, &re);
	}
    }
  if (kk == -1)
    return (-1);
  return (0);
}
