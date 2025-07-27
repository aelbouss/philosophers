/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/27 21:31:51 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t         mutex;

void    *func()
{
        pthread_mutex_lock(& mutex); 
        printf("the thread %ld is sleeping\n", pthread_self());
        pthread_mutex_unlock(&mutex);
        return (NULL);
}


int     main(int ac, char **av)
{
        ph_tools_t      *p;
        pthread_t       *threads;
        int             i;
        

        p = malloc(1 * sizeof(ph_tools_t));
        if (!p)
                return (1);
        if (parse_input(p, av, ac) != 0)
                return (1);
        pthread_mutex_init(&mutex, NULL);
        threads = malloc(p->ph_nbr * sizeof(pthread_t));
        if (!threads)
                return (ft_perr("Bad Allocation\n", 2));
        i = 0;
        while(i < p->ph_nbr)
        {
                if (pthread_create(&threads[i], NULL, func, NULL) != 0)
                        return (ft_perr("error : failed to create a thread\n", 2));
                i++;
        }
        i = 0;
        while(i < p->ph_nbr)
        {
                if (pthread_join(threads[i], NULL)!= 0)
                        return (ft_perr("error : failed to wait a tread\n", 2));
                i++;
        }
        return (0);
}