/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedule_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:36:54 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void		schedule_loop(t_db *db);
static t_i32	die_check(t_db *db);

void	schedule(t_db *db)
{
	++(db->num);
	while (db->common.start > ft_utime())
		usleep(1000);
	db->last_change = ft_utime();
	db->last_eat = db->last_change;
	schedule_loop(db);
}

static void	schedule_loop(t_db *db)
{
	if (db->common.nop == 1)
		return ;
	while (TRUE)
	{
		thinking(philo);
		if (die_check(philo))
			break ;
		eating(philo);
		if (die_check(philo))
			break ;
		sleeping(philo);
		if (die_check(philo))
			break ;
	}
	if (philo->state == S_EAT)
	{
		pthread_mutex_unlock(philo->left_mutex);
		pthread_mutex_unlock(philo->right_mutex);
	}
}

static t_i32	die_check(t_db *db)
{
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) < 0 || philo->eat_cnt == philo->common.limit)
	{
		++*(philo->end);
		pthread_mutex_unlock(philo->end_mutex);
		return (-1);
	}
	pthread_mutex_unlock(philo->end_mutex);
	return (0);
}
