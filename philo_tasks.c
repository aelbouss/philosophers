#include "philosophers.h"

int	setup_utils(t_all *a)
{
	if (!a)
		return (ft_perr("Bad Address\n", 2));
	a->si->infos = malloc(a->si->ph_nbr * sizeof(t_tools));
	if (!a->si->infos)
		return (ft_perr("Bad Allocation 2\n",  2));
	a->si->threads = malloc(a->si->ph_nbr * sizeof(pthread_t));
	if (!a->si->threads)
		return (ft_perr("Bad Allocation 3\n",  2));
	a->si->mutixes = malloc(a->si->ph_nbr * sizeof(int));
	if (!a->si->mutixes)
		return (ft_perr("Bad Allocation 4\n",  2));
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
	return(0);
}
/*
int	take_forks(t_tools *t, int pn)
{
	if (!t)
		return (ft_perr("Bad Address\n", 2));
}
*/