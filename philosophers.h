/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:51 by aelbouss          #+#    #+#             */
/*   Updated: 2025/08/02 01:53:22 by aelbouss         ###   ########.fr       */
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

typedef struct tools_s
{
        int     	nbr_eats;
        int     	philo_id;
        int     	philo_n;
	int		l_f;
	int		r_f;
	int		time_d;
        int		time_s;
        int		time_e;
	pthread_mutex_t	*mutixes;
}       t_tools;

typedef struct  s_philo
{
        int		ph_nbr;
        int		time_d;
        int		time_s;
        int		time_e;
        int		nbr_eats;
	pthread_mutex_t	*mutixes;
        pthread_t       *threads;
	t_tools		*infos;	
}	t_philo;

typedef	struct s_all
{
	t_tools	*pi;
	t_philo	*si;
}	t_all;


// prototypes
int	ft_is_numeric(char *str);
int	ft_perr(char *msg, int fd);
int	init_utils(char **av, t_all *a);
int	cnt_nbr(const char *s);
int	ft_atoi(const char *str);
int     parse_input(t_all *a, char **av, int ac);
int	initialize_each_philo_infos(t_philo *p, t_tools *infos, int philo_n);
int	setup_utils(t_all *a);
int	join_threads(t_all *a);
int	initialize_forks(t_all *a);
void	take_forks(t_tools *pi, long start_t);
void	put_the_forks_down(t_tools *pi);
void	eating(t_tools *pi, long start_t);
void	thinking(t_tools *pi, long start_t);
void	sleeping(t_tools *pi, long start_t);
long	get_time_stamp(void);

#endif