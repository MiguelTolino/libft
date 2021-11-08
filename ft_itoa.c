/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:26:10 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 17:07:52 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	is_negative(int n, int *nbr, int len)
{
	if (n < 0)
	{
		*nbr = -n;
		len++;
	}
	else
		*nbr = n;
}

void	ft_aux(size_t n, int len, char *str)
{
	if (n < 0)
		ft_fill(-n, len - 1, str);
	else
		ft_fill(n, len - 1, str);
}

static void	ft_fill(size_t n, int i, char *str)
{
	if (n >= 10)
		ft_fill(n / 10, i - 1, str);
	str[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1;
	is_negative(n, nbr, len);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_aux(n, len, *str);
	if (n < 0)
		str[0] = '-';
	return (str);
}
