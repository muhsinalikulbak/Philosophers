/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:33:35 by mkulbak           #+#    #+#             */
/*   Updated: 2024/10/24 17:32:59 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	digit_count(long *num)
{
	int		count;
	long	copy;

	copy = *num;
	count = 0;
	if (copy <= 0)
	{
		count++;
		*num = -*num;
		copy = -copy;
	}
	while (copy > 0)
	{
		count++;
		copy /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		count;
	long	long_num;

	long_num = n;
	count = 0;
	count = digit_count(&long_num);
	if (n < 0)
		n = -1;
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (!res)
		return (NULL);
	res[count--] = '\0';
	while (count >= 0)
	{
		res[count--] = long_num % 10 + '0';
		long_num /= 10;
	}
	if (n == -1)
		res[0] = '-';
	return (res);
}
