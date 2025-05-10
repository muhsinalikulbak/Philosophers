/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:59:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/10 16:09:07 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_current_time()
{
	struct timeval	*time;
	long			ms;

	gettimeofday(&time, NULL);
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}