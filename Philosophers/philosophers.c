/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/21 02:01:05 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philos;

	if (!argv_checker(argc, argv))
		return (error_manage(EINVAL, NULL, NULL));
	if (!initializer(&params, &philos, argc, argv))
		return (EXIT_FAILURE);


	free_resources(&params, philos);
}
