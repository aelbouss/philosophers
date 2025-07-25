#include "philosophers.h"

int     is_numeric_input(char **arr, int ac, ph_tools_t *p)
{
        int     i;

        i = 1;
        while (i < ac)
        {
            if (ft_is_numeric(arr[i]) != 0)
            {
                free(p);
                ft_perr("usage : <numeric arguments required> \n", 2);
                return (1);
            }
            i++;
        }
        return (0);
}

int     parse_input(ph_tools_t *p , char **av, int ac)
{
        if (is_numeric_input(av, ac , p) != 0)
                return (1);
        if (extract_args(ac, av, p) != 0)
                return (1);
        return (0);
}