/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:54:21 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 21:27:11 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	argv_checker(int argc, char **argv)
{
	int		i;
	char	*str_num;
	bool	check;

	if (argc < 5 || argc > 6)
		error_manage(EINVAL, NULL, NULL);
	i = 1;
	while (i < argc)
	{
		str_num = ft_strtrim(argv[i], " ");
		if (str_num == NULL)
			error_manage(EINVAL, NULL, NULL);
		if (str_num[0] == '\0')
		{
			free(str_num);
			error_manage(EINVAL, NULL, NULL);
		}
		check = (!digit_check(str_num) || !overflow_check(str_num, i));
		free(str_num);
		if (check)
			error_manage(EINVAL, NULL, NULL);
		i++;
	}
}
