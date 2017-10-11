#include "filler.h"

int	main(void)
{
  t_struct *data;
  int fd;
  char *buf;
  int kk;
  
  buf = NULL;
  if ((data = malloc(sizeof(t_struct))) == NULL)
    return (-1);
  data->player = 0;
  data->y_max = 0;
  data->x_max = 0;
  if ((fd = open("check", O_RDWR | O_CREAT, S_IRWXU)) < 0)
    return (-1);
  while ((kk = get_next_line(0, &buf)) > 0)
    {
      ft_putstr_fd(buf, fd);
      parse(data, buf);
      ft_putchar_fd('\n', fd);
    }
  if (kk == -1)
    return (-1);
  ft_putstr_fd("Player :", fd);
  ft_putnbr_fd(data->player, fd);
  ft_putstr_fd("\ny = ", fd);
  ft_putnbr_fd(data->y_max, fd);
  ft_putstr_fd("\nx = ", fd);
  ft_putnbr_fd(data->x_max, fd);
  close(fd);
}
