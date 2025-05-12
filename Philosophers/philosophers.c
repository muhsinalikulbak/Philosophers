/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 21:46:43 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philos;

	if (!argv_checker(argc, argv))
		return (error_manage(EINVAL, NULL, NULL, false));
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (philos == NULL)
		return (error_manage(EMALLOC, NULL, NULL, false));
	if (!initializer(&params, philos, argc, argv))
		return (EXIT_FAILURE);
	
}
