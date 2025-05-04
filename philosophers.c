/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/05 01:23:10 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main() 
{
    struct timeval start;
    struct timeval stop;
    long milisecond;

    gettimeofday(&start, NULL);
    for (int i = 0; i < 3000000; i++)
    {
        printf("\n");
    }
    gettimeofday(&stop, NULL);

    milisecond = (stop.tv_sec*1000 + stop.tv_usec / 1000) - (start.tv_sec*1000 + start.tv_usec / 1000);
    printf("3 Milyon for işlemi için Geçen toplam milisaniye : %ld\n", milisecond);
    usleep(3000000);
    int j = 0;    
    gettimeofday(&start, NULL);
    while (j < 3000000)
    {
        printf("\n");
        j++;
    }
    gettimeofday(&stop, NULL);

    milisecond = (stop.tv_sec*1000 + stop.tv_usec / 1000) - (start.tv_sec*1000 + start.tv_usec / 1000);
    printf("3 Milyon while işlemi için Geçen toplam milisaniye : %ld\n", milisecond);
    
}
