#include "philosophers.h"

int     is_numeric_input(char **av, int ac)
{
	int     i;

        i = 1;
        while (i < ac)
        {
            if (ft_is_numeric(av[i]) != 0)
            {
                ft_perr("Error : <numeric arguments required>\n", 2);
                return (1);
            }
            i++;
        }
        return (0);
}

int     parse_input(char **av, int ac)
{
        if ((ac - 1) != 4 && (ac -1) != 5)
        {
                ft_perr("Error : <Invalid Number Of Args>\n", 2);
                return (1);
        }
        if (is_numeric_input(av, ac ) != 0)
                return (1);
        if (over_under_flow_check(av, ac) != 0)
                return (1);
        return (0);
}

void	init_infos(int *data, t_all *a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		data[i - 1] = ft_atoi(av[i]);
		i++;
	}
	a->shared_data->ph_nbr = data[0];
	a->shared_data->time_d = data[1];
	a->shared_data->time_e = data[2];
	a->shared_data->time_s = data[3];
	if (ac == 6)
		a->shared_data->nbr_eats = data[4];
	else
		a->shared_data->nbr_eats = -1;
}

void	ft_free(t_all *a, int flag)
{
	if (!a)
		return;
	if (flag == 1)
	{
		free(a->threads);
		free(a);
		return;
	}
	if (flag == 2)
	{
		free(a->threads);
		free(a->mutixes);
		free(a);
		return;
	}
	if (flag == 3 || flag == 4)
	{
		free(a->threads);
		free(a->mutixes);
		free(a->private_data);
		if (flag == 4)
			free(a->shared_data);
		free(a);
		return ;
	}
}

t_all	*prepare_environement(char **av, int ac)
{
	t_all	*global;
	int	data[ac -1];
	int	pn;

	global = malloc(1 * sizeof(t_all));
	if (!global)
		return (NULL);
	pn = ft_atoi(av[1]);
	global->threads = malloc(pn * sizeof(pthread_t));
	if (!global->threads)
		return (ft_free(global, 1), NULL);
	global->mutixes = malloc(pn * sizeof(pthread_mutex_t));
	if (!global->mutixes)
		return (ft_free(global, 2), NULL);
	global->private_data = malloc(pn * sizeof(t_tools));
	if (!global->private_data)
		return (ft_free(global, 3), NULL);
	global->shared_data = malloc(1 * sizeof(t_philo));
	if (!global->shared_data)
		return (ft_free(global, 4), NULL);
	global->philo_infos = malloc(pn * sizeof(t_tools));
	if (!global)
		return (NULL);
	init_infos(data, global, ac, av);
	return (global);
}
