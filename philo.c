/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/25 02:04:28 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int     main(int ac, char **av)
{
        ph_tools_t      *p;

        p = malloc(1 * sizeof(ph_tools_t));
        if (!p)
                return (1);
        if (parse_input(p, av, ac) != 0)
                return (1);
        printf("the  nbr of  philos : %d\n", p->ph_nbr);
        printf("the time to die : %d\n", p->time_d);
        printf("the time to eat : %d\n", p->time_e);
        printf("the time to sleep : %d\n", p->time_s);
        printf("the nbr each philo must eat : %d\n", p->nbr_eats);
        free(p);
        return (0);
}