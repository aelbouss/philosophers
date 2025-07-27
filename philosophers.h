/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:51 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/27 23:19:00 by aelbouss         ###   ########.fr       */
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


// templates
typedef struct  ph_tools_s
{
        int     ph_nbr;
        int     time_d;
        int     time_s;
        int     time_e;
        int     nbr_eats;
}       ph_tools_t;

// prototypes
int     ft_is_numeric(char *str);
int     ft_perr(char *msg, int fd);
int     init_utils(char **av, ph_tools_t *p);
int     cnt_nbr(const char *s);
int     ft_atoi(const char *str);
int     parse_input(ph_tools_t *p , char **av, int ac);


#endif