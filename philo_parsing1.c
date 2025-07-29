#include "philosophers.h"

int     is_numeric_input(char **arr, int ac, t_all *all)
{
        int     i;

        i = 1;
        while (i < ac)
        {
            if (ft_is_numeric(arr[i]) != 0)
            {
                free(all);
                ft_perr("Error : <numeric arguments required>\n", 2);
                return (1);
            }
            i++;
        }
        return (0);
}
void    error_case(t_all *all)
{
        free(all);
        ft_perr("Error : <argument out of range>\n", 2);
}

int     over_under_flow_check(t_all *a, int  ac)
{
        if (a->si->ph_nbr > INT_MAX || a->si->ph_nbr < INT_MIN || a->si->ph_nbr < 0)
                return(error_case(a), 1);
        if (a->si->time_d > INT_MAX || a->si->time_d < INT_MIN || a->si->time_d < 0)
                return(error_case(a), 1);
        if (a->si->time_e > INT_MAX || a->si->time_e < INT_MIN || a->si->time_e < 0)
                return(error_case(a), 1);
        if (a->si->time_s > INT_MAX || a->si->time_s < INT_MIN || a->si->time_s < 0)
                return(error_case(a), 1);
        if (ac-1 == 5)
        {
            if (a->si->nbr_eats > INT_MAX || a->si->nbr_eats < INT_MIN || a->si->nbr_eats < 0)
                return(error_case(a), 1);     
        }
	a->si->mutixes = malloc(a->si->ph_nbr * sizeof(int));
	if (!a->si->mutixes)
		return (ft_perr("Bad aocation  1\n", 2));
        return (0);
}

int     parse_input(t_all *a, char **av, int ac)
{
        if ((ac - 1) != 4 && (ac -1) != 5)
        {
                free(a);
                ft_perr("Error : <Invalid Number Of Args>\n", 2);
                return (1);
        }
        if (is_numeric_input(av, ac , a) != 0)
                return (1);
        if (init_utils(av, a) != 0)
                return (1);
        if (over_under_flow_check(a, ac) != 0)
                return (1);
        return (0);
}
