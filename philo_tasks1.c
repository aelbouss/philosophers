#include "philosophers.h"

void	take_forks(t_tools *pi)
{
	int	l;
	int	r;

	l = pi->l_f;
	r = pi->r_f;
	pthread_mutex_lock(&pi->mutixes[l]);
	pthread_mutex_lock(&pi->mutixes[r]);
	printf("philo %d has taken the first fork\n",pi->philo_n);
	printf("philo %d has taken the second fork\n",pi->philo_n);
}
void	put_the_forks_down(t_tools *pi)
{
	int	l;
	int	r;

	l = pi->l_f;
	r = pi->r_f;
	pthread_mutex_unlock(&pi->mutixes[l]);
	pthread_mutex_unlock(&pi->mutixes[r]);
}

void	eating(t_tools *pi)
{
	
	printf("the philo %d is eating\n",pi->philo_n);
	usleep(pi->time_s * 1000);
}
void	sleeping(t_tools *pi)
{
	printf("the pilo %d is sleeping\n", pi->philo_n);
	usleep(pi->time_s * 1000);
}

void	thinking(t_tools *pi)
{
	printf("the philo %d is thinking\n",pi->philo_n);
}
