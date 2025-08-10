#include "philosophers.h"

void	simulation(t_tools *pi)
{
	while (1)
	{
		pthread_mutex_lock(&pi->data->death_mutex);
		if (pi->data->death_flag == 1)
		{
			pthread_mutex_unlock(&pi->data->death_mutex);
			return;
		}
		pthread_mutex_unlock(&pi->data->death_mutex);
		take_forks(pi);
		eating(pi);
		put_the_forks_down(pi);
		sleeping(pi);
		thinking(pi);
		if (pi->data->ph_nbr % 2 != 0)
			usleep(500);
	}
}

void	clean_table(t_all *g)
{
	int	i;

	join_threads(g);
	i = 0;
	while (i < g->shared_data->ph_nbr)
	{
		pthread_mutex_destroy(&g->shared_data->mutixes[i]);
		i++;
	}
	pthread_mutex_destroy(&g->shared_data->meals_mutex);
	pthread_mutex_destroy(&g->shared_data->death_mutex);
	free(g->shared_data->mutixes);
	free(g->threads);
	free(g->shared_data);
	free(g->private_data);
	free(g);
}