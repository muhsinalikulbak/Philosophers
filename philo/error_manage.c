/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:09:48 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/23 17:23:02 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	write_colored(char *color, char *text)
{
	write(1, color, ft_strlen(color));
	write(1, text, ft_strlen(text));
	write(1, RESET, ft_strlen(RESET));
}

static void	ft_perror(char *message)
{
	write_colored(GREEN, "\n---- ");
	write_colored(RED, message);
	write_colored(GREEN, " ----\n");
}

int	error_manage(int error_code, t_params *param, t_philo *phi)
{
	if (error_code == EINVAL)
		ft_perror("Invalid Argument!");
	else if (error_code == STDERR)
	{
		ft_perror("Error!");
		free_resources(param, phi);
	}
	return (EXIT_FAILURE);
}
