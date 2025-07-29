/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:51 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/29 18:41:28 by aelbouss         ###   ########.fr       */
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


typedef struct tools_s
{
        int     nbr_eats;
        int     philo_id;
        int     philo_n;
	int	left_fork;
	int	right_fork;
	int	time_d;
        int	time_s;
        int	time_e;
	int	*mutixes;
}       t_tools;

// templates
typedef struct  s_philo
{
        int		ph_nbr;
        int		time_d;
        int		time_s;
        int		time_e;
        int		nbr_eats;
	int		*mutixes;
        pthread_t       *threads;
        t_tools         *p_infos;
}	t_philo;

// prototypes
int	ft_is_numeric(char *str);
int	ft_perr(char *msg, int fd);
int	init_utils(char **av, t_philo *p);
int	cnt_nbr(const char *s);
int	ft_atoi(const char *str);
int	parse_input(t_philo *p , char **av, int ac);
int	initialize_each_philo_infos(t_philo *p, t_tools *infos, int philo_n);
int	setup_utils(t_philo *p);

#endif