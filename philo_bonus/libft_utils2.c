/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:56:32 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/03 10:40:37 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = malloc(count * size);
	if (!res)
		return (NULL);
	while (i < count * size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup("\0"));
	if (start + len > s_len)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

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
