#include "philosophers.h"

void	take_forks(t_tools *pi)
{
	int	left;
	int	right;

	left = pi->l_f;
	right = pi->r_f;
	if (pi->philo_nbr % 2 == 0)
	{
		pthread_mutex_lock(&pi->data->mutixes[right]);
		pthread_mutex_lock(&pi->data->mutixes[left]);
	}
	else
	{
		pthread_mutex_lock(&pi->data->mutixes[left]);
		pthread_mutex_lock(&pi->data->mutixes[right]);
	}
	pthread_mutex_lock(&pi->data->meals_mutex);
	pi->l_meal_e = get_time_stamp() - pi->data->start_t;
	pi->data->meals_flag++;
	pthread_mutex_unlock(&pi->data->meals_mutex);
	desplay_logs(pi->philo_nbr, "has taken a fork", pi->data);
	desplay_logs(pi->philo_nbr, "has taken a fork", pi->data);
}

void	eating(t_tools *pi)
{
	desplay_logs(pi->philo_nbr, "is eating", pi->data);
	ft_usleep(pi->data->time_e, pi->data);
}

void	put_the_forks_down(t_tools *pi)
{
	int	left;
	int	right;

	left = pi->l_f;
	right = pi->r_f;
	pthread_mutex_unlock(&pi->data->mutixes[left]);
	pthread_mutex_unlock(&pi->data->mutixes[right]);
}

void	desplay_logs(int philo_nbr, char *log, t_philo *sh)
{
	pthread_mutex_lock(&sh->death_mutex);
	if (sh->death_flag != 1)
	{
		printf("%ld %d %s\n", (get_time_stamp() - sh->start_t), philo_nbr, log);
		pthread_mutex_unlock(&sh->death_mutex);
		return ;
	}
	pthread_mutex_unlock(&sh->death_mutex);
}

int	init_mutixes_infos(t_all *g)
{
	int	i;

	i = 0;
	//pthread_mutex_init(&g->shared_data->death_lock, NULL);
	pthread_mutex_init(&g->shared_data->death_mutex, NULL);
	pthread_mutex_init(&g->shared_data->meals_mutex, NULL);
	while (i < g->shared_data->ph_nbr)
	{
		if (initialize_each_philo_infos(g->shared_data, &g->private_data[i], i + 1) != 0)
		{
			ft_perr("Error : failedd  initializing philos\n", 2);
			return (1);
		}
		if (pthread_mutex_init(&g->shared_data->mutixes[i], NULL) != 0)
		{
			ft_perr("Error : failed initialize mutixes\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
