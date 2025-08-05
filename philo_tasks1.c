#include "philosophers.h"

void	take_forks(t_tools *pi, long start_t)
{
	int	l;
	int	r;

	l = pi->l_f;
	r = pi->r_f;
	pthread_mutex_lock(&pi->mutixes[l]);
	pthread_mutex_lock(&pi->mutixes[r]);
	printf("%ld  %d has taken the left fork\n",(get_time_stamp() - start_t), pi->philo_n);
	printf("%ld %d has taken the right fork\n", (get_time_stamp() - start_t), pi->philo_n);
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

void	eating(t_tools *pi, long start_t)
{
	
	printf("%ld %d is eating\n", (get_time_stamp() - start_t), pi->philo_n);
	usleep(pi->time_s * 1000);
}
void	sleeping(t_tools *pi, long start_t)
{
	printf("%ld %d is sleeping\n",(get_time_stamp() - start_t), pi->philo_n);
	usleep(pi->time_s * 1000);
}

void	thinking(t_tools *pi, long start_t)
{
	printf("%ld %d is thinking\n", (get_time_stamp() - start_t), pi->philo_n);
}
