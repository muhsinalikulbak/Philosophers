/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:52:42 by mkulbak           #+#    #+#             */
/*   Updated: 2024/10/25 22:36:13 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
