/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:37:00 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(t_u64 us)
{
	us += ft_utime();
	while (us > ft_utime())
		usleep(1000);
}

t_u64	ft_utime(void)
{
	t_timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000000ull + cur.tv_usec);
}

t_u64	ft_utom(t_u64 us)
{
	return (us / 1000);
}

t_u64	ft_mtou(t_u64 ms)
{
	return (ms * 1000);
}
