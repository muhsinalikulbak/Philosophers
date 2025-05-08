/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:18:48 by mkulbak           #+#    #+#             */
/*   Updated: 2024/10/18 17:45:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*concat;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	concat = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!concat)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		concat[len1] = s1[len1];
		len1++;
	}
	while (s2[len2])
	{
		concat[len1 + len2] = s2[len2];
		len2++;
	}
	concat[len1 + len2] = '\0';
	return (concat);
}
