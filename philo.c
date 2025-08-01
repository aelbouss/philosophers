/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/01 05:00:11 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*behaviour(void *info)
{
	t_tools *pi;

	pi = (t_tools *)info;
	take_forks(pi);
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