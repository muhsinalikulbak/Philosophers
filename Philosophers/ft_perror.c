/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 02:46:04 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 18:59:29 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	write_colored(char *color, char *text)
{
	write(1, color, ft_strlen(color));
	write(1, text, ft_strlen(text));
	write(1, RESET, ft_strlen(RESET));
}

void	ft_perror(char *message)
{
	write_colored(GREEN, "\n---- ");
	write_colored(RED, message);
	write_colored(GREEN, " ----\n");
}
