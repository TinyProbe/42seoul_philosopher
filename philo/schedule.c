#include "philo.h"

static t_i32	die_sync_usleep(t_u64 us, t_philo *philo);

void	*schedule(void *db)
{

	return (db);
}

static t_i32	die_sync_usleep(t_u64 us, t_philo *philo)
{
	static t_u64	target;
	static t_u64	cur;

	target = us + ft_utime();
	while (TRUE)
	{
		cur = ft_utime();
		if ((cur - philo->last_eat) > philo->common->life)
			return (-1);
		if (target <= cur)
			return (0);
		usleep(1);
	}
}
