/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/06 01:23:29 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *print(void *arg)
{
    printf("Merhaba ben Thread\n");
    int *num = malloc(sizeof(int)*1);
    *num = 185;
    return (void*)(num);
}
int main() 
{
    pthread_t thread;
    void *return_value;

    pthread_create(&thread, NULL, print, NULL);
    pthread_join(thread, &return_value);
    printf("Gelen değer : %d\n", *(int*)return_value);
}
