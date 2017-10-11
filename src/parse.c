#include "filler.h"


int	get_piece(t_struct *d, char *buf)
{
  size_t lol;
  int i;

  i = 0;
  lol = ft_strlen("Piece ");
  if (ft_strncmp(buf, "Piece ", lol) == 0)
    {
      d->piece_y_max = ft_atoi(buf + lol);
      d->piece_x_max = ft_atoi(buf + lol +
			      ft_strlen(ft_itoa(d->piece_y_max)));
      if (!((d->piece = alloc_tab(d->piece, d->piece_x_max, d->piece_y_max))))
	return (-1);
      return (1);
    }
  while (d->piece[i][0] != 0)
    i++;
   d->piece[i] = ft_strcpy(d->piece[i], buf);
  if (i + 1 == d->piece_y_max)
    {
      d->piece_filled = 1;
      return (1);
    }
  return (1);
}

int	get_map(t_struct *d, char *buf)
{
  int i;

  i = 0;
  if (ft_strncmp(buf, "    ", ft_strlen("    ")) == 0)
    {
      if (!((d->map = alloc_tab(d->map, d->x_max, d->y_max))))
	return (-1);
    }
  d->map = fill_tab(buf, d->map, d->y_max, &d->map_filled);
  return (1);
}

int	get_size(t_struct *d, char *buf)
{
  size_t lol;

  lol = ft_strlen("Plateau ");
  if (ft_strncmp(buf,"Plateau ", lol) != 0)
    return (0);
  d->y_max = ft_atoi(buf + lol);
  d->x_max = ft_atoi(buf + lol + ft_strlen(ft_itoa(d->y_max)));
  return (1);
}

int	get_player(t_struct *d, char *buf)
{
  size_t lol;

  lol = ft_strlen("$$$ exec p");
  if (ft_strncmp(buf,"$$$ exec p", lol) != 0)
    return (0);
  d->player = ft_atoi(buf + lol);
  return (1);
}

void	parse(t_struct *d, char *buf)
{
  if (d->player == 0)
    {
      if (get_player(d, buf) == 1)
	return ;
    }
  else if (d->x_max == 0 || d->y_max == 0)
    {
      if (get_size(d, buf) == 1)
	return ;
    }
  else if (d->map_filled == 0)
    {
      if (get_map(d, buf) == 1)
	return ;
    }
  else if (d->piece_filled == 0)
    {
      if (get_piece(d, buf) == 1)
	return ;
    }
  else
    d->c_tipar = 1;
}
