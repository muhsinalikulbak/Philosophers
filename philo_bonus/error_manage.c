/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:57:56 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/25 21:58:09 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
