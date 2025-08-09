#include "philosophers.h"

void	sleeping(t_tools *pi)
{
	desplay_logs(pi->philo_nbr, "is sleeping", pi->data);
	ft_usleep(pi->data->time_s);
}
void 	thinking(t_tools *pi)
{
		desplay_logs(pi->philo_nbr, "is thinking", pi->data);
}


void	is_dead(t_tools *pi, t_all *g)
{
	int	i;

	while (pi->data->death_flag != 1)
	{
		i = 0;
		while(i < g->shared_data->ph_nbr)
		{
			if ((get_time_stamp() - g->private_data[i].l_meal_e) > g->shared_data->time_d)
			{
				g->shared_data->death_flag = 1;
				printf("%ld %d is dead\n",(get_time_stamp() - g->shared_data->start_t), g->private_data[i].philo_nbr);
				pthread_mutex_unlock(&g->shared_data->death_mutex);
				break ;
			}
			pthread_mutex_unlock(&g->shared_data->death_mutex);
			i++;
		}
	}
}

void	ft_usleep(int ms)
{
	long	start;

	start = get_time_stamp();
	while ((get_time_stamp() - start) < ms)
		usleep(100); // 0, 01 mill sec
}