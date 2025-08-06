#include "philosophers.h"

int	setup_utils(t_all *a)
{
	if (!a)
		return (ft_perr("Bad Address\n", 2));
	a->si->infos = malloc(a->si->ph_nbr * sizeof(t_tools));
	if (!a->si->infos)
		return (ft_perr("Bad Allocation\n",  2));
	a->si->threads = malloc(a->si->ph_nbr * sizeof(pthread_t));
	if (!a->si->threads)
		return (ft_perr("Bad Allocation\n",  2));
	a->si->mutixes = malloc(a->si->ph_nbr * sizeof(pthread_mutex_t));
	if (!a->si->mutixes)
		return (ft_perr("Bad Allocation\n",  2));
	if (initialize_forks(a) != 0)
		return (ft_perr("error occcurs while setting up the forks\n",  2));
	return (0);
}
int	initialize_each_philo_infos(t_philo *p, t_tools *infos, int philo_n)
{
	if (!p || !infos)
		return (ft_perr("Bad Address \n", 2));
	infos->philo_n = philo_n;
	infos->time_d = p->time_d;
	infos->time_e = p->time_e;
	infos->time_s = p->time_s;
	infos->mutixes = p->mutixes;
	infos->threads =  p->threads;
	infos->ph_nbr = p->ph_nbr;
	return(0);
}

int	initialize_forks(t_all *a)
{
	int	i;

	if (!a)
		return (ft_perr("Bad Address\n", 2));
	i = 0;
	while(i < a->si->ph_nbr)
	{
		if (i + 1 == a->si->ph_nbr)
		{
			a->si->infos[i].r_f = 0;
			a->si->infos[i].l_f = i;
			return (0);
		}
		a->si->infos[i].l_f = i;
		a->si->infos[i].r_f = i + 1;
		i++;
	}
	return (0);
}

void	th_sleep(int time)
{
	usleep(time * 1000);
}

// when  usleep  gives  correct  results 

