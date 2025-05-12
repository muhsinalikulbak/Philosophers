/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:09:48 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 21:08:01 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_manage(int error_code, t_params *param, t_philo *phi, bool init)
{
	if (error_code == EINVAL)
		ft_perror("Invalid Argument!");
	else if (error_code == EMALLOC)
	{
		ft_perror("Malloc Error!");
		if (param == NULL && phi == NULL)
			return (EXIT_FAILURE);
		free_resources(param, phi, init);
	}
	return (EXIT_FAILURE);
}
