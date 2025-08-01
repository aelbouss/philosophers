#include "philosophers.h"

void	take_forks(t_tools	*pi)
{
	int	l;
	int	r;

	l = pi->l_f;
	r = pi->r_f;
	pthread_mutex_lock(&pi->mutixes[l]);
	pthread_mutex_lock(&pi->mutixes[r]);
	printf("philo %d has taken the first fork\n",pi->philo_n);
	printf("philo %d has taken the second fork\n",pi->philo_n);
	pthread_mutex_unlock(&pi->mutixes[l]);
	pthread_mutex_unlock(&pi->mutixes[r]);
}