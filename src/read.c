#include "filler.h"

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
  if ((fd = open("check", O_RDWR | O_CREAT, S_IRWXU)) < 0)
    return (-1);
  while ((kk = get_next_line(0, &buf)) > 0)
    {
      parse(&d, buf);
      if (d.map_filled == 1)
	{
	  int i = 0;
	  ft_putstr_fd("\n[MAP]\n", fd);
	  while (d.map[i])
	    {
	      ft_putstr_fd(d.map[i], fd);
	      ft_putchar_fd('\n', fd);
	      i++;
	    }
	}
    }
  if (kk == -1)
    return (-1);
  ft_putstr_fd("\n map->filled =", fd);
  ft_putnbr_fd(d.map_filled, fd);
  close(fd);
  return (0);
}
