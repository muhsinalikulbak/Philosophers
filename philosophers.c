/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:45:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/07 01:35:07 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Mikrosaniye cinsinden geçerli zamanı döndür
long long current_micros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

int main() {
    long long start, end, elapsed;
    int sleep_duration = 500000;  // 500,000 mikrosaniye = 0.5 saniye
        
    printf("Testing usleep(%d)...\n", sleep_duration);
    
    start = current_micros();
    usleep(sleep_duration);
    end = current_micros();
    
    elapsed = end - start;
    
    printf("Requested sleep: %d microseconds\n", sleep_duration);
    printf("Actual sleep: %lld microseconds\n", elapsed);
    printf("Difference: %lld microseconds\n", elapsed - sleep_duration);
    
    return 0;
}
