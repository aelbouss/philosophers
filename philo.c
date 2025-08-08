/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/08 22:28:48 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*behaviour(void *info)
{
	t_tools 	*pi;

	pi = (t_tools *)info;
	printf("im the philo %d\n", pi->philo_nbr);
	printf("the start  time  is  %ld\n",(get_time_stamp() - pi->data->start_t));
	/*while (1)
	{
		
		if (eating(pi, start_t) != 0)
			break;
		put_the_forks_down(pi);
		if (sleeping(pi, start_t) != 0)
			break;
		if (thinking(pi, start_t) != 0)
			break;
	}
			*/
	return (NULL);
}

int	join_threads(t_all *g)
{
	int	i;

	i = 0;
	while (i < g->shared_data->ph_nbr)
	{
		if (pthread_join(g->threads[i], NULL) != 0)
			return (ft_perr("Error occurs while watinng threads\n", 2), 1);
		i++;
	}
	return (0);
}

int     main(int ac, char **av)
{
	t_all	*global;

	
	if (parse_input(av, ac) != 0)
		return (1);
	global = prepare_environement(av, ac);
	if (!global)
		return (1);
	if(setup_philos_utils(global) != 0)
		return (1);
	if (create_threads(global) != 0)
		return (1);
	join_threads(global);
        return (0);
}

// must setup the mutex for synchronize the tasks
// impliment  the  actions  (think) , (take the forks), (eat) , (put the forks down) , (sleep)