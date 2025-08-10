#include "philosophers.h"

void	sleeping(t_tools *pi)
{
	desplay_logs(pi->philo_nbr, "is sleeping", pi->data);
	ft_usleep(pi->data->time_s, pi->data);
}
void 	thinking(t_tools *pi)
{
		desplay_logs(pi->philo_nbr, "is thinking", pi->data);
}

void	check_starvation(t_all *g)
{
	int	i;

	i = 0;
	while(i < g->shared_data->ph_nbr)
	{
		pthread_mutex_lock(&g->shared_data->death_mutex);
		pthread_mutex_lock(&g->shared_data->meals_mutex);
		if (((get_time_stamp()- g->shared_data->start_t)- g->private_data[i].l_meal_e) > g->shared_data->time_d)
		{
			g->shared_data->death_flag = 1;
			printf("%ld %d is dead\n",(get_time_stamp() - g->shared_data->start_t), g->private_data[i].philo_nbr);
			pthread_mutex_unlock(&g->shared_data->death_mutex);
			pthread_mutex_unlock(&g->shared_data->meals_mutex);
			break ;
		}
		pthread_mutex_unlock(&g->shared_data->death_mutex);
		pthread_mutex_unlock(&g->shared_data->meals_mutex);
		i++;
	}
}

void	simulation_controller(t_all *g)
{
	while (g->shared_data->death_flag != 1 && g->shared_data->all_eat != 1)
	{

		check_starvation(g);
		if (g->shared_data->nbr_eats != -1)
			check_nbr_meals(g);
	}
}

void	ft_usleep(int ms, t_philo *p)
{
	long	start;

	start = get_time_stamp();
	while ((get_time_stamp() - start) < ms)
	{
		pthread_mutex_lock(&p->death_mutex);
		if (p->death_flag == 1)
		{
			pthread_mutex_unlock(&p->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&p->death_mutex);
		usleep(100); // 0, 01 mill sec
	}
}