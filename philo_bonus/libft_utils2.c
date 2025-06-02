/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:56:32 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/25 21:57:07 by muhsin           ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;
	int		*map;

	map = (int *)ft_calloc(256, sizeof(int));
	if (!map)
		return (NULL);
	while (*set)
	{
		map[(int)*set] = -1;
		set++;
	}
	start = 0;
	end = ft_strlen(s1) - 1 ;
	while (s1[start] && map[(int)s1[start]] == -1)
		start++;
	while (s1[start] && map[(int)s1[end]] == -1)
		end--;
	result = ft_substr(s1, start, end - start + 1);
	free(map);
	return (result);
}
