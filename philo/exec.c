#include "philo.h"

static void	init_resource(t_db *db);
static void	delete_resource(t_db *db);

void	exec(t_db *db)
{
	init_resource(db);
	loop(db);
	delete_resource(db);
}

static void	init_resource(t_db *db)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
	{
		pthread_mutex_init(db->last_eat_mutex + idx, NULL);
		pthread_mutex_init(db->fork_mutex + idx, NULL);
	}
	pthread_mutex_init(&(db->created_mutex), NULL);
	pthread_mutex_init(&(db->end_mutex), NULL);
	idx = -1;
	while (++idx < db->common.nop)
	{
		pthread_create(
			&(db->philo[idx].thread), NULL, schedule, db->philo + idx);
		pthread_mutex_lock(&(db->created_mutex));
		db->created++;
		pthread_mutex_unlock(&(db->created_mutex));
	}
}

static void	delete_resource(t_db *db)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
		pthread_join(db->philo[idx].thread, NULL);
	idx = -1;
	while (++idx < db->common.nop)
	{
		pthread_mutex_destroy(db->last_eat_mutex + idx);
		pthread_mutex_destroy(db->fork_mutex + idx);
	}
	pthread_mutex_destroy(&(db->created_mutex));
	pthread_mutex_destroy(&(db->end_mutex));
}
