#include "philo.h"

t_u64	ft_usleep(t_u64 us)
{
	t_u64	target;
	t_u64	cur;

	target = us + ft_utime();
	while (TRUE)
	{
		cur = ft_utime();
		if (target <= cur)
			break ;
		usleep(ft_usync(100));
	}
	return (cur - target);
}

t_u64	ft_utime()
{
	t_timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000000ull + cur.tv_usec);
}

t_u64	ft_utom(t_u64 us)
{
	return (us / 1000);
}

t_u64	ft_mtou(t_u64 ms)
{
	return (ms * 1000);
}

t_u64	ft_usync(t_u64 us)
{
	return (us * 0.86);
}
