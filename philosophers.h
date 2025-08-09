/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:51 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/09 18:07:41 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H


// headers
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>


// templates


typedef struct  s_philo
{
	int				time_d;
    int				time_s;
    int				time_e;
	int				ph_nbr;
	int				nbr_eats;
	int				death_flag;
	long			start_t;
	pthread_mutex_t	*mutixes;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	death_mutex;
}	t_philo;


typedef struct tools_s
{
    int				nbr_eats;
	long			l_meal_e;
	int				l_f;
	int				r_f;
	int				philo_nbr;
	t_philo			*data;
}	t_tools;


typedef	struct	s_all
{
	t_philo		*shared_data;
	t_tools		*private_data;
	pthread_t	*threads;
}	t_all;


// prototypes




void	ft_perr(char *msg, int fd);
int     ft_is_numeric(char *str);
int     is_numeric_input(char **av, int ac);
int	ft_atoi(const char *str);
int	cnt_nbr(const char *s);
int     over_under_flow_check(char **av, int  ac);
int	parse_input(char **av, int ac);
void	init_infos(int *data, t_all *a, int ac, char **av);
t_all	*prepare_environement(char **av, int ac);
void	ft_free(t_all *a, int flag);
long	get_time_stamp(void);
int	initialize_forks(t_all *g);
int	initialize_each_philo_infos(t_philo *p, t_tools *infos, int philo_n);
void	*behaviour(void *info);
int	join_threads(t_all *g);
int	create_threads(t_all *g);
int	init_mutixes_infos(t_all *g);
int	setup_philos_utils(t_all *g);
void	desplay_logs(int philo_nbr, char *log, t_philo *sh);
void	eating(t_tools *pi);
void	take_forks(t_tools *pi);
void	put_the_forks_down(t_tools *pi);
void	sleeping(t_tools *pi);
void 	thinking(t_tools *pi);
void	ft_usleep(int ms);
void	is_dead(t_tools *pi, t_all *g);
void	fill_philos_death_flag(t_all *g);


#endif


/*void	is_dead(t_tools *pi, t_all *g)
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
*/