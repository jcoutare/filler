#include "filler.h"


int	get_piece(t_struct *data, char *buf)
{
  
}

int	get_map(t_struct *data, char *buf)
{
  int i;

  i = 0;
  if (ft_strncmp(buf, "    ", ft_strlen("    ")) == 0)
    {
      if (!((data->map = malloc(sizeof(char *) * y_max + 1))))
	return (-1);
      data->map[y_max] = '/0';
      while (data->map[i])
	{
	  if (!((data->map[i] = malloc(sizeof(char)
				       * x_max + 1))))
	    return (-1);
	  data->map[i][x_max] = '\0';
	}
    }
}

int	get_size(t_struct *data, char *buf)
{
  if (ft_strncmp(buf,"Plateau ", ft_strlen("Plateau ")) != 0)
    return (0);
  data->y_max = ft_atoi(buf + ft_strlen("Plateau "));
  data->x_max = ft_atoi(buf + ft_strlen("Plateau ")
		    + ft_strlen(ft_itoa(data->y_max)));
  return (1);
}

int	get_player(t_struct *data, char *buf)
{
  if (ft_strncmp(buf,"$$$ exec p", ft_strlen("$$$ exec p")) != 0)
    return (0);
  data->player = ft_atoi(buf + ft_strlen("$$$ exec p"));
  return (1);
}

void	parse(t_struct *data, char *buf)
{
  if (data->player == 0)
    {
      if (get_player(data, buf) == 1)
	return ;
    }
  if (data->x_max == 0 || data->y_max == 0)
    {
      if (get_size(data, buf) == 1)
	return ;
    }
  if (get_map(data, buf) == 1)
    return ;
  if (get_piece(data, buf) == 1)
    return ; 
}
