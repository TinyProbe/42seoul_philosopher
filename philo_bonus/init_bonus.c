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

t_i32	init(t_db *db, t_i32 ac, t_i8 **av)
{
	if (check(ac, av))
		return (-1);
	db->common.start = ft_utime() + 1000000;
	db->common.nop = ft_stoi(av[1]);
	db->common.life = ft_mtou(ft_stoi(av[2]));
	db->common.eat = ft_mtou(ft_stoi(av[3]));
	db->common.sleep = ft_mtou(ft_stoi(av[4]));
	db->common.limit = -1;
	if (ac == 6)
		db->common.limit = ft_stoi(av[5]);
	if (db->common.nop == 0 || db->common.nop > MAX_PHILO
		|| db->common.life < ft_mtou(60) || db->common.life > ft_mtou(10000)
		|| db->common.eat < ft_mtou(60) || db->common.eat > ft_mtou(10000)
		|| db->common.sleep < ft_mtou(60) || db->common.sleep > ft_mtou(10000))
		return (-1);
	db->last_change = db->common.start;
	db->last_eat = db->common.start;
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
