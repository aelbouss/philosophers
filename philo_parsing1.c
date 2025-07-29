#include "philosophers.h"

int     is_numeric_input(char **arr, int ac, t_philo *p)
{
        int     i;

        i = 1;
        while (i < ac)
        {
            if (ft_is_numeric(arr[i]) != 0)
            {
                free(p);
                ft_perr("Error : <numeric arguments required>\n", 2);
                return (1);
            }
            i++;
        }
        return (0);
}
void    error_case(t_philo *p)
{
        free(p);
        ft_perr("Error : <argument out of range>\n", 2);
}

int     over_under_flow_check(t_philo *p, int  ac)
{
        if (p->ph_nbr > INT_MAX || p->ph_nbr < INT_MIN || p->ph_nbr < 0)
                return(error_case(p), 1);
        if (p->time_d > INT_MAX || p->time_d < INT_MIN || p->time_d < 0)
                return(error_case(p), 1);
        if (p->time_e > INT_MAX || p->time_e < INT_MIN || p->time_e < 0)
                return(error_case(p), 1);
        if (p->time_s > INT_MAX || p->time_s < INT_MIN || p->time_s < 0)
                return(error_case(p), 1);
        if (ac-1 == 5)
        {
            if (p->nbr_eats > INT_MAX || p->nbr_eats < INT_MIN || p->nbr_eats < 0)
                return(error_case(p), 1);     
        }
	p->mutixes = malloc(p->ph_nbr * sizeof(int));
	if (!p->mutixes)
		return (ft_perr("Bad Allocation\n", 2));
        return (0);
}

int     parse_input(t_philo *p , char **av, int ac)
{
        if ((ac - 1) != 4 && (ac -1) != 5)
        {
                free(p);
                ft_perr("Error : <Invalid Number Of Args>\n", 2);
                return (1);
        }
        if (is_numeric_input(av, ac , p) != 0)
                return (1);
        if (init_utils(av, p) != 0)
                return (1);
        if (over_under_flow_check(p, ac) != 0)
                return (1);
        return (0);
}
