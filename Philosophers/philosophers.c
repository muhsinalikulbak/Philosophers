/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 02:44:51 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	write_colored(char *color, char *text)
{
	write(1, color, ft_strlen(color));
	write(1, text, ft_strlen(text));
	write(1, RESET, ft_strlen(RESET));
}

static void	exit(char *message)
{
	write_colored(GREEN, "\n---- ");
	write_colored(RED, message);
	write_colored(GREEN, " ----\n");
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_params	*params;
	t_philo		*philos;

	if (!argv_checker(argc, argv))
		exit("Invalid Argument!");
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	initializer(&params, philos, argc, argv);
}
