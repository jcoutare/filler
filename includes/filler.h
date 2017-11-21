/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:48:55 by jcoutare          #+#    #+#             */
/*   Updated: 2017/11/21 12:10:40 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ICI printf("ICI\n");
# define LA printf("LA\n");
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int	fd;

typedef struct			s_struct
{
	int				nb_stars;
	char			**map;
	int				x_max;
	int				y_max;
	char			**piece;
	int			     player;
	int				map_filled;
	int				piece_filled;
	int				piece_x_max;
	int				piece_y_max;
}						t_struct;

int		la_rebalade(t_struct *d);
int		cpt_dot(t_struct *d);
void	affiche(t_struct d);
void	print_result_fd(int y, int x);
int		place(t_struct *d, int i, int j);
void	print_result(int y, int x);
int		la_balade(t_struct *d);
void	cpt_stars(t_struct *d);
void	free_tab(char **tab);
void    str_nb_fd(char *str, int nb);
void    str_str_fd(char *str, char *str1);
int	fill_tab(t_struct *d, char *buf);
int	fill_piece(t_struct *d, char *buf);
char	**alloc_tab(char **map, int x, int y);
void	parse(t_struct *d, char *buf);
int     get_player(t_struct *d, char *buf);
int     get_size(t_struct *d, char *buf);
int     get_map(t_struct *d, char *buf);
int     get_piece(t_struct *d, char *buf);
#endif
