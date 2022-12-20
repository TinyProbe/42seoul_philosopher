/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:32:13 by tkong             #+#    #+#             */
/*   Updated: 2022/12/20 23:32:21 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		schedule_loop(t_philo *philo);
static t_i32	die_check(t_philo *philo);

void	*schedule(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	while (TRUE)
	{
		pthread_mutex_lock(philo->created_mutex);
		if (*(philo->created) == philo->common.nop)
		{
			pthread_mutex_unlock(philo->created_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->created_mutex);
	}
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->common.start = ft_utime();
	philo->last_change = philo->common.start;
	*(philo->last_eat) = philo->common.start;
	pthread_mutex_unlock(philo->last_eat_mutex);
	if (!(philo->num & 1))
		ft_usleep(10000);
	else if (philo->num == philo->common.nop)
		ft_usleep(20000);
	schedule_loop(philo);
	return (NULL);
}

static void	schedule_loop(t_philo *philo)
{
	if (philo->common.nop == 1)
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

static t_i32	die_check(t_philo *philo)
{
	pthread_mutex_lock(philo->created_mutex);
	if (*(philo->created) < 1 || philo->eat_cnt == philo->common.limit)
	{
		--*(philo->created);
		pthread_mutex_unlock(philo->created_mutex);
		return (-1);
	}
	pthread_mutex_unlock(philo->created_mutex);
	return (0);
}
