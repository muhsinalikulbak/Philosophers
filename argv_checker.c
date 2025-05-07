/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:30:40 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/07 21:43:48 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

static bool	digit_check(char *str)
{
	int	plus;
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (i < len)
	{
		if (str[i] == '+')
			plus++;
		else if (str[i] == '-' || !ft_is_digit(str[i]))
			return (false);
		i++;
	}
}

bool	argv_checker(int argc, char **argv)
{
	int	i;

	if (argc < 4 || argc > 5)
		return (false);
	i = 0;
	while (i < argc)
	{
		if (!digit_check(argv[i]))
			return (false);
	}
}

// number_of_philosophers, time_to_die,  time_to_eat, time_to_sleep
// [number_of_times_each_philosopher_must_eat]