/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:54:08 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 21:27:30 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philos;

	argv_checker(argc, argv);
	initializer(&params, &philos, argc, argv);
	start_simulation(&params, philos);
	free_resources(&params, philos);
}
