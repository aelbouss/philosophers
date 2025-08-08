/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/08 16:38:53 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
void	*behaviour(void *info)
{
	t_tools 	*pi;
	long int	start_t;

	pi = (t_tools *)info;
	start_t = get_time_stamp();
	while (1)
	{
		if (take_forks(pi, start_t) != 0)
			break ;
		if (eating(pi, start_t) != 0)
			break;
		put_the_forks_down(pi);
		if (sleeping(pi, start_t) != 0)
			break;
		if (thinking(pi, start_t) != 0)
			break;
	}
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

*/
int     main(int ac, char **av)
{
	t_all	*global;

	
	if (parse_input(av, ac) != 0)
		return (1);
	global = prepare_environement(av, ac);
	if (!global)
		return (1);
	if (initialize_forks(global) != 0)
		return  (1);
	if (create_threads(global) != 0)
		return (1);
	/*
	join_threads(global);
	*/
        return (0);
}

// must setup the mutex for synchronize the tasks
// impliment  the  actions  (think) , (take the forks), (eat) , (put the forks down) , (sleep)