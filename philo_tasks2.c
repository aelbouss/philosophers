#include "philosophers.h"

long	get_time_stamp(void)
{
	struct timeval tv;
	long	ms_time;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	ms_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (ms_time);
}

int	is_dead(t_tools * pi)
{
	if (current_time - last_meal_eaten >= time_to_die) ;
}