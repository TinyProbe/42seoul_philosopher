/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:32:14 by tkong             #+#    #+#             */
/*   Updated: 2022/12/20 23:32:21 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	shift_state(t_philo *philo)
{
	if (philo->state == S_THINK)
	{
		pthread_mutex_lock(philo->last_eat_mutex);
		philo->last_change = ft_utime();
		*(philo->last_eat) = philo->last_change;
		pthread_mutex_unlock(philo->last_eat_mutex);
		philo->state = S_EAT;
	}
	else if (philo->state == S_EAT)
	{
		philo->last_change = ft_utime();
		philo->eat_cnt++;
		philo->state = S_SLEEP;
	}
	else if (philo->state == S_SLEEP)
	{
		philo->last_change = ft_utime();
		philo->state = S_THINK;
	}
}
