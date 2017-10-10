/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:59:06 by jcoutare          #+#    #+#             */
/*   Updated: 2017/09/29 15:14:02 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*nbtostr(char *str, int lgt, unsigned long long n, int neg)
{
	if ((str = malloc(sizeof(char) * (lgt + 1))) == NULL)
		return (NULL);
	str[lgt--] = '\0';
	while (n >= 10)
	{
		str[lgt--] = (n % 10 + '0');
		n = n / 10;
	}
	str[lgt] = (n + '0');
	if (neg == 2)
		str[0] = '-';
	return (str);
}

char			*ft_itoa_ull(unsigned long long n)
{
	char						*str;
	int							lgt;
	unsigned long				nb;
	int							neg;

	lgt = 1;
	neg = 1;
	str = NULL;
	nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		lgt++;
	}
	return (nbtostr(str, lgt, n, neg));
}
