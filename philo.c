/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/31 04:41:50 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*behaviour(void *ptr)
{
	t_tools	*routine;
	int	l;
	int	r;

	routine = (t_tools *)ptr;
	l = routine->l_f;
	r = routine->r_f;
	pthread_mutex_lock(&routine->mutixes[l]);
	pthread_mutex_lock(&routine->mutixes[r]);
	th_sleep(routine->time_e);
	pthread_mutex_unlock(&routine->mutixes[l]);
	pthread_mutex_unlock(&routine->mutixes[r]);
	/*printf("the  philo number : %d\n",routine->philo_n);
	printf("the  philo's time to die: %d\n",routine->time_d);
	printf("the  philo's time to eat: %d\n",routine->time_e);
	printf("the  philo's time to sleep: %d\n",routine->time_s);
	printf("the  philo's left forks : %d\n", routine->l_f);
	printf("the  philo's right forks : %d\n", routine->r_f); */
	printf("the philo %d start eating\n", routine->philo_n);
	printf("\n#####################################################################\n");
	return (NULL);
}

int	create_threads(t_all *a)
{
	int	i;

	i = 0;
	while (i < a->si->ph_nbr)
	{
		initialize_each_philo_infos(a->si, &a->si->infos[i], i + 1);
		if(pthread_create(&a->si->threads[i], NULL, behaviour, &a->si->infos[i]) != 0)
			return (ft_perr("error while creating threads\n", 2));
		i++;
	}
	return (0);
}
int	join_threads(t_all *a)
{
	int	i;

	i = 0;
	while (i < a->si->ph_nbr)
	{
		if (pthread_join(a->si->threads[i], NULL) != 0)
			return (ft_perr("Error occurs while watinng threads\n", 2));
		i++;
	}
	return (0);
}

int     main(int ac, char **av)
{
	t_all	*global;

        global = malloc(1  * sizeof(t_all));
        if (!global)
                return (1);
	global->si = malloc(1  * sizeof(t_philo));
	if (!global->si)
		return (1);
	global->pi = malloc(1 * sizeof(t_tools));
	if (!global->pi)
		return (1);
        if (parse_input(global, av, ac) != 0)
                return (1);
	if (setup_utils(global) != 0)
		return (1);
	if (create_threads(global) != 0)
		return (1);
	join_threads(global);
        return (0);
}

// must setup the mutex for synchronize the tasks
// impliment  the  actions  (think) , (take the forks), (eat) , (put the forks down) , (sleep)