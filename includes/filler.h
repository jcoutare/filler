/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:48:55 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/10 14:37:41 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ICI printf("ICI\n");
# define LA printf("LA\n");
# include "libft.h"
# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int	fd;
typedef struct			s_struct
{
  char				**map;
  int				x_max;
  int				y_max;
  char				**piece;
  int					player;
  int				map_filled;
  int				piece_filled;
  int				c_tipar;
}						t_struct;

char	**fill_tab(char *buf, char **tab, int y, int *c_fini);
char	**alloc_tab(char **map, int x, int y);
void	parse(t_struct *d, char *buf);
int     get_player(t_struct *d, char *buf);
int     get_size(t_struct *d, char *buf);
int     get_map(t_struct *d, char *buf);
int     get_piece(t_struct *d, char *buf);
#endif
