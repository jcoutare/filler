#include "filler.h"

char	**alloc_tab(char **tab, int x, int y)
{
  int i;

  i = 0;
  if (!((tab = malloc(sizeof(char *) * y + 1))))
    return (NULL);
  tab[y] = 0;
  while (i < y)
    {
      if (!((tab[i] = malloc(sizeof(char) * x + 1))))
	return (NULL);
      ft_memset(tab[i], '\0', x);
      i++;
    }
  return (tab);
}
char	*cpy_only_with_src(char *dest, char *buf, char *src)
{
  int i;
  int j;
  int k;

  k = 0;
  i = 0;
  while (buf[k])
    {
      j = 0;
      while (src[j])
	{
	  if (buf[k] == src[j])
	    {
	      dest[i] = buf[k];
	      i++;
	    }
	  j++;
	}
      k++;
    }
  return (dest);
}

char	**fill_tab(char *buf, char **tab, int y, int *c_fini)
{
  int i;

  i = 0;
  while (tab[i][0] != 0)
    i++;
    tab[i] = cpy_only_with_src(tab[i], buf, "XO.");
  if (i + 1 == y)
    {
      *c_fini = 1;
      return (tab);
    }
  return (tab);
}

void	str_nb_fd(char *str, int nb)
{
  ft_putstr_fd(str, fd);
  ft_putnbr_fd(nb, fd);
  ft_putchar_fd('\n', fd);
}

void	str_str_fd(char *str, char *str1)
{
  ft_putstr_fd(str, fd);
  ft_putstr_fd(str1, fd);
  ft_putchar_fd('\n', fd);
}
