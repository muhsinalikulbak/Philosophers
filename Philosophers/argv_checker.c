/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:30:40 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/08 03:23:47 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	overflow_check(char *str)
{
	int		i;
	long	num;

	i = 0;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (false);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

static bool	digit_check(char *str)
{
	int	plus;
	int	i;

	if (ft_strlen(str) == 1 && str[0] == '0')
		return (false);
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
	if ((plus == 1 && str[0] == '+') || plus == 0)
		return (true);
	return (false);
}

bool	argv_checker(int argc, char **argv)
{
	int		i;
	char	*str_num;

	if (argc < 5 || argc > 6)
		return (false);
	i = 1;
	while (i < argc)
	{
		str_num = ft_strtrim(argv[i], " ");
		if (!digit_check(str_num) || !overflow_check(str_num))
		{
			free(str_num);
			return (false);
		}
		free(str_num);
		i++;
	}
	return (true);
}

// number_of_philosophers, time_to_die,  time_to_eat, time_to_sleep
// [number_of_times_each_philosopher_must_eat]