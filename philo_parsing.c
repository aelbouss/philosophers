/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:19:46 by aelbouss          #+#    #+#             */
/*   Updated: 2025/07/30 00:02:06 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     ft_perr(char *msg, int fd)
{
        int     i;

        if (!msg)
                return (1);
        i = 0;
        while (msg[i])
        {
                write(fd, &msg[i], 1);
                i++;
        }
        return (1);
}

int	cnt_nbr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	if (!str)
		return (0);
	if (cnt_nbr(str) >= 20)
		return (-1);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
int     ft_is_numeric(char *str)
{
        int     i;

        if (!str)
                return (1);
        i = 0;
        while (str[i])
        {
                if (!(str[i] >= '0' && str[i] <= '9'))
                        return (1);
                i++;
        }
        return (0);
}


int     init_utils(char **av, t_all *a)
{
        a->si->ph_nbr = ft_atoi(av[1]);
        a->si->time_d = ft_atoi(av[2]);
        a->si->time_e = ft_atoi(av[3]);
        a->si->time_s = ft_atoi(av[4]);
        a->si->nbr_eats = ft_atoi(av[5]);
        return (0);
}
