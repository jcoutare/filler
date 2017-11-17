/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:06:31 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/17 10:15:21 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_memset(tab[i], '\0', x + 1);
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

int	fill_piece(t_struct *d, char *buf)
{
	int i;

	i = 0;
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

int	fill_tab(t_struct *d, char *buf)
{
	int i;

	i = 0;
	while (d->map[i][0] != 0)
		i++;
    d->map[i] = cpy_only_with_src(d->map[i], buf, "XO.");
	if (i + 1 == d->y_max)
    {
		d->map_filled = 1;
		return (1);
    }
	return (1);
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
