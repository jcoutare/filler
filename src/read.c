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

int	main(void)
{
  t_struct d;
  char *buf;
  int kk;
  
  buf = NULL;
  d.player = 0;
  d.y_max = 0;
  d.x_max = 0;
  d.map_filled = 0;
  d.piece_filled = 0;
  d.piece_x_max = 0;
  d.piece_y_max = 0;
  d.c_tipar = 0;
  if ((fd = open("check", O_RDWR | O_CREAT, S_IRWXU)) < 0)
    return (-1);
  while ((kk = get_next_line(0, &buf)) > 0)
    {
      parse(&d, buf);
      if (d.piece_filled == 1)
	affiche(d);
    }
  if (kk == -1)
    return (-1);
  close(fd);
  return (0);
}
