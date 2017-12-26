/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:48:55 by jcoutare          #+#    #+#             */
/*   Updated: 2017/12/26 16:44:08 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct			s_nul
{
	int stars;
	int miam;
	int a;
	int b;
}						t_nul;

typedef struct			s_struct
{
  int			selec;
   int			pos2_X;
  int			pos2_Y;
  int			pos1_X;
  int			pos1_Y;
	char			gentil;
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

void	algo_un(t_struct *d, int *re);
void	algo_deux(t_struct *d, int *re);
void	algo_trois(t_struct *d, int *re);
void	algo_quatre(t_struct *d, int *re);
void	clear(t_struct *d);
void	cpt_stars(t_struct *d);
int		place(t_struct *d, int i, int j);
void	c_tipar(t_struct *d, int *re);
void	get_pos(t_struct *d, int *re);
void	choose_algo(t_struct *d, int *re);
int		la_promenade(t_struct *d);
int		la_repromenade(t_struct *d);
int		la_rebalade(t_struct *d);
int		cpt_dot(t_struct *d);
void	affiche(t_struct d);
void	print_result_fd(int y, int x);
void	print_result(int y, int x);
int		la_balade(t_struct *d);
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
