#include "philosophers.h"

int	take_forks(t_tools *pi, long start_t)
{
	int	l;
	int	r;

	l = pi->l_f;
	r = pi->r_f;
	pthread_mutex_lock(&pi->mutixes[l]);
	pthread_mutex_lock(&pi->mutixes[r]);
	pi->l_meal_e = (get_time_stamp() - start_t);
	if (is_dead(pi, start_t) != 0)
		return (1);
	printf("%ld %d has taken the left fork\n",(get_time_stamp() - start_t), pi->philo_n);
	printf("%ld %d has taken the right fork\n", (get_time_stamp() - start_t), pi->philo_n);
	return  (0);
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

int	eating(t_tools *pi, long start_t)
{
	(void)start_t;
	if (is_dead(pi, start_t) != 0)
		return (1);
	printf("%ld %d is eating\n", pi->l_meal_e, pi->philo_n);
	usleep(pi->time_s * 1000);
	return (0);
}
int	sleeping(t_tools *pi, long start_t)
{
	if (is_dead(pi, start_t) != 0)
		return (1);
	printf("%ld %d is sleeping\n",(get_time_stamp() - start_t), pi->philo_n);
	usleep(pi->time_s * 1000);
	return  (0);
}

int	thinking(t_tools *pi, long start_t)
{
	if (is_dead(pi, start_t) != 0)
		return (1);
	printf("%ld %d is thinking\n", (get_time_stamp() - start_t), pi->philo_n);
	return  (0);
}
