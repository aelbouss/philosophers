#include "philosophers.h"

long	get_time_stamp(void)
{
	struct timeval tv;
	long	ms_time;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	ms_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (ms_time);
}

int	initialize_each_philo_infos(t_philo *shared_d, t_tools *private_d, int philo_n)
{
	if (!shared_d || !private_d)
		return (ft_perr("Bad Address \n", 2), 1);
	private_d->data = shared_d;
	private_d->philo_nbr = philo_n;
	private_d->nbr_eats = 0;
	return(0);
}

int	initialize_forks(t_all *g)
{
	int	i;

	if (!g)
		return (ft_perr("Bad Address\n", 2), 1);
	i = 0;
	while(i < g->shared_data->ph_nbr)
	{
		if (i + 1 == g->shared_data->ph_nbr)
		{
			g->private_data[i].r_f = 0;
			g->private_data[i].l_f = i;
			return (0);
		}
		g->private_data[i].l_f = i;
		g->private_data[i].r_f = i + 1;
		i++;
	}
	return (0);
}

int	create_threads(t_all *g)
{
	int	i;

	if (!g)
		return (ft_perr("Bad Address\n", 2), 1);
	g->shared_data->start_t = get_time_stamp();
	i = 0;
	while (i < g->shared_data->ph_nbr)
	{
		if (i % 2 == 0)
			pthread_create(&(g->threads[i]), NULL, behaviour, &(g->private_data[i]));
		i++;
	}
	usleep(498);
	i = 0;
	while (i < g->shared_data->ph_nbr)
	{
		if (i % 2 != 0)
			pthread_create(&(g->threads[i]), NULL, behaviour, &(g->private_data[i]));
		i++;
	}
	return (0);
}

int	setup_philos_utils(t_all *g)
{
	if (initialize_forks(g) != 0)
		return (1);
	if (init_mutixes_infos(g) != 0)
		return (1);
	return (0);
}

// when  usleep  gives  correct  results 

