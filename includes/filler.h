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

typedef struct			s_struct
{
	char				**map;
	char				**piece;
	int					player;
}						t_struct;

#endif
