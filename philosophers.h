/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:51 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/08 16:37:21 by aelbouss         ###   ########.fr       */
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
	int		time_d;
        int		time_s;
        int		time_e;
	int		ph_nbr;
	int		nbr_eats;
	long		start_t;
}	t_philo;


typedef struct tools_s
{
        int     	nbr_eats;
        int     	philo_n;
	long		l_meal_e;
	int		l_f;
	int		r_f;
	int		phi_n;
	t_philo		*data;
}       t_tools;


typedef	struct	s_all
{
	t_philo		*shared_data;
	t_tools		*private_data;
	pthread_t	*threads;
	pthread_mutex_t	*mutixes;
	t_tools		*philo_infos;
	int		death_flag;
	pthread_mutex_t	death_lock;
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


#endif
/*
int	ft_is_numeric(char *str);


int	init_utils(char **av, t_all *a);

int	ft_atoi(const char *str);
int     parse_input(t_all *a, char **av, int ac);
int	initialize_each_philo_infos(t_philo *p, t_tools *infos, int philo_n);
int	setup_utils(t_all *a);
int	join_threads(t_all *a);
int	initialize_forks(t_all *a);
int	take_forks(t_tools *pi, long start_t);
void	put_the_forks_down(t_tools *pi);
int	eating(t_tools *pi, long start_t);
int	thinking(t_tools *pi, long start_t);
int	sleeping(t_tools *pi, long start_t);
long	get_time_stamp(void);
int	threads_claim(pthread_t *threads, int pn);
int	is_dead(t_tools * pi, long start_t);


*/
