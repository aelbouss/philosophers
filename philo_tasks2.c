#include "philosophers.h"

/*


int	threads_claim(pthread_t *threads, int pn)
{
	int	i;

	if  (!threads || pn < 2)
		return (1);
	i = 0;
	while(i < pn)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			ft_perr("error occurs whiler joining  threads\n", 2);
			return (1);
		}
		printf("hereeee\n");
		i++;
		
	}
	return (0);
}

int	is_dead(t_tools * pi, long start_t)
{
	long	time_s;
	//  if (current_time - last_meal_eaten >= time_to_die) ;
	time_s = (get_time_stamp() - start_t);
	if ((time_s - pi->l_meal_e) >= pi->time_d)
	{
		printf("%ld %d is died\n", time_s, pi->philo_n);
		if(threads_claim(pi->threads, pi->ph_nbr) != 0)
			return (1);
		return (1);
	}
	return (0);
}
*/


void	sleeping(t_tools *pi)
{
	desplay_logs(pi->philo_nbr, "is sleeping", pi->data);
	usleep(pi->data->time_s * 1000);
}
void 	thinking(t_tools *pi)
{
	desplay_logs(pi->philo_nbr, "is thinking", pi->data);
}