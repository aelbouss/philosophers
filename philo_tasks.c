#include "philosophers.h"

int	setup_utils(t_philo *p)
{
	if (!p)
		return (ft_perr("Bad Address\n", 2));
	p->p_infos = malloc(p->ph_nbr * sizeof(t_tools));
	if (!p->p_infos)
		return (ft_perr("Bad Allocation\n",  2));
	p->threads = malloc(p->ph_nbr * sizeof(pthread_t));
	if (!p->threads)
		return (ft_perr("Bad Allocation\n",  2));
	p->mutixes = malloc(p->ph_nbr * sizeof(int));
	if (!p->mutixes)
		return (ft_perr("Bad Allocation\n",  2));
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
	return(0);
}

int	take_forks(t_tools *t, int pn)
{
	if (!t)
		return (ft_perr("Bad Address\n", 2));
}