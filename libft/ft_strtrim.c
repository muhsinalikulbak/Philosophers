/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:06:49 by mkulbak           #+#    #+#             */
/*   Updated: 2024/10/29 08:08:46 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
