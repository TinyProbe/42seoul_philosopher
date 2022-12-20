/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:36:42 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_i32	check(t_i32 ac, t_i8 **av);
static void		init_db(t_db *db);

t_i32	init(t_db *db, t_i32 ac, t_i8 **av)
{
	if (check(ac, av))
		return (-1);
	db->common.start = ft_utime();
	db->common.nop = ft_stoi(av[1]);
	db->common.life = ft_mtou(ft_stoi(av[2]));
	db->common.eat = ft_mtou(ft_stoi(av[3]));
	db->common.sleep = ft_mtou(ft_stoi(av[4]));
	db->common.limit = -1;
	if (ac == 6)
		db->common.limit = ft_stoi(av[5]);
	if (db->common.nop == 0 || db->common.nop > MAX_THREAD
		|| db->common.life < ft_mtou(60) || db->common.eat < ft_mtou(60)
		|| db->common.sleep < ft_mtou(60))
		return (-1);
	init_db(db);
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

static void	init_db(t_db *db)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
	{
		db->last_eat[idx] = db->common.start;
		db->philo[idx].common = db->common;
		db->philo[idx].num = idx + 1;
		db->philo[idx].last_change = db->common.start;
		db->philo[idx].last_eat = db->last_eat + idx;
		db->philo[idx].created = &(db->created);
		db->philo[idx].end = &(db->end);
		db->philo[idx].last_eat_mutex = db->last_eat_mutex + idx;
		db->philo[idx].left_mutex = db->fork_mutex + idx;
		db->philo[idx].right_mutex
			= db->fork_mutex + ((idx + 1) % db->common.nop);
		db->philo[idx].created_mutex = &(db->created_mutex);
		db->philo[idx].end_mutex = &(db->end_mutex);
	}
}
