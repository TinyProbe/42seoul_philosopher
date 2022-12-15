#include "philo.h"

static t_i32	check(t_i32 ac, t_i8 **av);
static void		init_philo(t_db *db);

t_i32	init(t_db *db, t_i32 ac, t_i8 **av)
{
	if (check(ac, av))
		return (-1);
	db->common.start_time = ft_utime();
	db->common.nop = ft_stoi(av[1]);
	db->common.life = ft_mtou(ft_stoi(av[2]));
	db->common.eat = ft_mtou(ft_stoi(av[3]));
	db->common.sleep = ft_mtou(ft_stoi(av[4]));
	db->common.limit = -1;
	if (ac == 6)
		db->common.limit = ft_stoi(av[5]);
	if (db->common.nop > MAX_THREAD)
		return (-1);
	init_philo(db);
	return (0);
}

static t_i32	check(t_i32 ac, t_i8 **av)
{
	t_i32	idx;

	while (ac-- > 1)
	{
		idx = -1;
		while (av[ac][++idx])
			if (!ft_isdigit(av[ac][idx]))
				return (-1);
	}
	return (0);
}

static void	init_philo(t_db *db)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
	{
		db->philo[idx].num = idx + 1;
		db->philo[idx].last_change = db->common.start_time;
		db->philo[idx].last_eat = db->common.start_time;
		db->philo[idx].common = &(db->common);
		db->philo[idx].left_fork = db->fork + idx;
		db->philo[idx].right_fork = db->fork + ((idx + 1) % db->common.nop);
		db->philo[idx].left_mutex = db->fork_mutex + idx;
		db->philo[idx].right_mutex = db->fork_mutex + ((idx + 1) % db->common.nop);
	}
}
