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


int	initialize_each_philo_infos(t_philo *p, t_tools *infos, int philo_n)
{
	if (!p || !infos)
		return (ft_perr("Bad Address \n", 2), 1);
	infos->data = p;
	infos->phi_n = philo_n;
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
			g->philo_infos[i].r_f = 0;
			g->philo_infos[i].l_f = i;
			return (0);
		}
		g->philo_infos[i].l_f = i;
		g->philo_infos[i].r_f = i + 1;
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
	while (i < g->shared_data->ph_nbr)
	{

	}
}





void	th_sleep(int time)
{
	usleep(time * 1000);
}

// when  usleep  gives  correct  results 

