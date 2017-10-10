/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:43 by jcoutare          #+#    #+#             */
/*   Updated: 2017/09/29 15:13:42 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*nbtostr(char *str, int lgt, long long n, int neg)
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

char			*ft_itoa(long long n)
{
	char						*str;
	int							lgt;
	unsigned long				nb;
	int							neg;

	lgt = 1;
	neg = 1;
	str = NULL;
	if (n < -9223372036854775807)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	if (n < 0 && neg++)
	{
		n *= -1;
		lgt++;
	}
	nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		lgt++;
	}
	return (nbtostr(str, lgt, n, neg));
}
