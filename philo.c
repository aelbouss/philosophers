/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/29 18:41:56 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t         mutex;


void	*behaviour(void *ptr)
{
	t_tools	*routine;

	routine = (t_tools *)ptr;
	printf("the  philo number : %d\n",routine->philo_n);
	printf("the  philo's time to die: %d\n",routine->time_d);
	printf("the  philo's time to eat: %d\n",routine->time_e);
	printf("the  philo's time to sleep: %d\n",routine->time_s);
	return (NULL);
}

int	create_threads(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->ph_nbr)
	{
		if (initialize_each_philo_infos(p, &p->p_infos[i], i+1) != 0)
			return (1);
		p->mutixes[i] = i+1;
		if (pthread_create(&p->threads[i], NULL, behaviour, &p->p_infos[i]) != 0)
			return (ft_perr("error due threads creation\n", 2));
		p->mutixes[i] = i + 1;
		i++;	
	}
	return (0);
}
int	join_threads(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->ph_nbr)
	{
		if (pthread_join(p->threads[i], NULL) != 0)
			return (ft_perr("Error occurs while watinng threads\n", 2));
		i++;
	}
	return (0);
}

int     main(int ac, char **av)
{
        t_philo      *p;

        p = malloc(1  * sizeof(t_philo));
        if (!p)
                return (1);
        if (parse_input(p, av, ac) != 0)
                return (1);
	if (setup_utils(p) != 0)
		return (1);
	if (create_threads(p) != 0)
		return (1);
	join_threads(p);
        return (0);
}

// must setup the mutex for synchronize the tasks
// impliment  the  actions  (think) , (take the forks), (eat) , (put the forks down) , (sleep)