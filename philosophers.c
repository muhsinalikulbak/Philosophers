/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/06 01:16:53 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *print(void *arg)
{
    printf("Merhaba ben Thread\n");
    return NULL;
}
int main() 
{
    pthread_t thread;
    pthread_create(&thread, NULL, print, NULL);
    printf("Burası main thread\n");
}
