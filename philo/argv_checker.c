/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:30:40 by mkulbak           #+#    #+#             */
/*   Updated: 2025/06/06 09:59:34 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	overflow_check(char *str, int idx)
{
	int		i;
	long	num;

	i = 0;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (false);
	num = ft_atol(str);
	if (idx == 5)
	{
		if (num >= 0 && num <= 2147483647L)
			return (true);
		else
			return (false);
	} 
	if (num > 2147483647L || num == 0)
		return (false);
	return (true);
}

static bool	digit_check(char *str)
{
	int	plus;
	int	i;

	i = 0;
	plus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
			plus++;
		else if (str[i] == '-' || !ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if ((ft_strlen(str) != 1 && plus == 1 && str[0] == '+') || plus == 0)
		return (true);
	return (false);
}

bool	argv_checker(int argc, char **argv)
{
	int		i;
	char	*str_num;
	bool	check;

	if (argc < 5 || argc > 6)
		return (false);
	i = 1;
	while (i < argc)
	{
		str_num = ft_strtrim(argv[i], " ");
		if (str_num == NULL)
			return (false);
		if (str_num[0] == '\0')
		{
			free(str_num);
			return (false);
		}
		check = (!digit_check(str_num) || !overflow_check(str_num, i));
		free(str_num);
		if (check)
			return (false);
		i++;
	}
	return (true);
}
