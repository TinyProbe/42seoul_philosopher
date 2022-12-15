#include "philo.h"

static void	init_mutex(t_db *db);
static void	init_thread(t_db *db);

void	exec(t_db *db)
{
	init_mutex(db);
	init_thread(db);
	loop(db);
}

static void	init_mutex(t_db *db)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
		pthread_mutex_init(db->fork_mutex + idx, NULL);
	pthread_mutex_init(&(db->common.event_mutex), NULL);
}

static void	init_thread(t_db *db)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
	{
		pthread_create(&(db->philo[idx].thread),
			NULL, schedule, db->philo + idx);
		ft_usleep(10);
	}
	idx = -1;
	while (++idx < db->common.nop)
		pthread_detach(db->philo[idx].thread);
}
