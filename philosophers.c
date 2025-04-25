/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/25 02:53:04 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int counter = 0;

void* print_hello(void* arg) 
{
    pthread_mutex_t *lock = (pthread_mutex_t *)arg;

    pthread_mutex_lock(lock);
    
    for (int i = 0; i < 5555; i++) 
    {
        counter++;
    }
    pthread_mutex_unlock(lock);
    return NULL;
}

int main() 
{
    pthread_t t1, t2;
    pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

    pthread_create(&t1, NULL, print_hello, &my_mutex);
    pthread_create(&t2, NULL, print_hello,  &my_mutex);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("counter : %d\n", counter);
    return 0;
}
