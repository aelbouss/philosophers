/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:42 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/10 03:08:07 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*behaviour(void *info)
{
	t_tools	*pi;

	pi = (t_tools *)info;
	if (pi->data->ph_nbr == 1)
	{
		pthread_mutex_lock(&pi->data->mutixes[pi->l_f]);
		desplay_logs(pi->philo_nbr, "has taken a fork", pi->data);
		pthread_mutex_unlock(&pi->data->mutixes[pi->l_f]);
		return (NULL);
	}
	if (pi->data->nbr_eats != -1)
		simulation_with_nbr_meals(pi);
	else
		simulation(pi);
	return (NULL);
}

void	simulation_with_nbr_meals(t_tools *pi)
{
	int	i;

	i = 0;
	while (i < pi->data->nbr_eats)
	{
		pthread_mutex_lock(&pi->data->death_mutex);
		if (pi->data->death_flag == 1)
		{
			pthread_mutex_unlock(&pi->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&pi->data->death_mutex);
		take_forks(pi);
		eating(pi);
		put_the_forks_down(pi);
		sleeping(pi);
		thinking(pi);
		if (pi->data->ph_nbr % 2 != 0)
			usleep(500);
		i++;
	}
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

void	check_nbr_meals(t_all *g)
{
	pthread_mutex_lock(&g->shared_data->meals_mutex);
	if (g->shared_data->meals_flag == (g->shared_data->nbr_eats * \
			g->shared_data->ph_nbr))
	{
		g->shared_data->all_eat++;
		pthread_mutex_unlock(&g->shared_data->meals_mutex);
		return ;
	}
	pthread_mutex_unlock(&g->shared_data->meals_mutex);
}

int	main(int ac, char **av)
{
	t_all	*global;

	if (parse_input(av, ac) != 0)
		return (1);
	global = prepare_environement(av, ac);
	if (!global)
		return (1);
	if (setup_philos_utils(global) != 0)
		return (1);
	if (create_threads(global) != 0)
		return (1);
	simulation_controller(global);
	clean_table(global);
	return (0);
}
