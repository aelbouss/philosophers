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

	pthread_mutex_lock(&pi->data->death_lock);
	while (pi->data->death_flag != 1)
	{
		pthread_mutex_unlock(&pi->data->death_lock);
		i = 0;
		while (i < pi->data->ph_nbr)
		{
			pthread_mutex_lock(&pi->data->time_mutex);
			if (((get_time_stamp() - pi->data->start_t) - g->private_data[i].l_meal_e) > g->shared_data[i].time_d)
			{

				printf("simulatoin starts  at : %ld\n", (get_time_stamp() - pi->data->start_t));
				printf("time  spended : %ld\n", (get_time_stamp() - pi->data->start_t) - g->private_data[i].l_meal_e);
				printf("time to  die : %d\n",g->shared_data[i].time_d);
				pthread_mutex_unlock(&pi->data->time_mutex);
				desplay_logs(pi->philo_nbr, "is dead", pi->data);
				pthread_mutex_lock(&pi->data->death_lock);
				pi->data->death_flag = 1;
				pthread_mutex_unlock(&pi->data->death_lock);
				break;
			}
			pthread_mutex_unlock(&pi->data->time_mutex);
			i++;
		}
	}
	//pthread_mutex_unlock(&pi->data->death_lock);
}

void	ft_usleep(int ms)
{
	long	start;

	start = get_time_stamp();
	while ((get_time_stamp() - start) < ms)
		usleep(100); // 0, 01 mill sec
}