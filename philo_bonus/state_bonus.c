/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:36:57 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	shift_state(t_philo *philo)
{
	if (philo->state == S_THINK)
	{
		pthread_mutex_lock(philo->last_eat_mutex);
		philo->last_change = ft_utime();
		*(philo->last_eat) = philo->last_change;
		pthread_mutex_unlock(philo->last_eat_mutex);
		philo->eat_cnt++;
		philo->state = S_EAT;
	}
	else if (philo->state == S_EAT)
	{
		philo->last_change = ft_utime();
		philo->state = S_SLEEP;
	}
	else if (philo->state == S_SLEEP)
	{
		philo->last_change = ft_utime();
		philo->state = S_THINK;
	}
}
