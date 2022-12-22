/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:32:11 by tkong             #+#    #+#             */
/*   Updated: 2022/12/20 23:32:21 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	death_detect(t_db *db);

void	loop(t_db *db)
{
	while (db->common.start > ft_utime())
		ft_usleep(1000);
	while (TRUE)
	{
		death_detect(db);
		pthread_mutex_lock(&(db->created_mutex));
		if (db->created < 1)
		{
			pthread_mutex_unlock(&(db->created_mutex));
			break ;
		}
		pthread_mutex_unlock(&(db->created_mutex));
	}
}

static void	death_detect(t_db *db)
{
	t_i32	idx;
	t_u64	cur;

	idx = -1;
	while (++idx < db->common.nop)
	{
		pthread_mutex_lock(db->last_eat_mutex + idx);
		cur = ft_utime();
		if (cur - db->last_eat[idx] > db->common.life)
		{
			pthread_mutex_lock(&(db->created_mutex));
			db->created = 0;
			printf("%llu %d died\n",
				ft_utom(cur - db->common.start), idx + 1);
			pthread_mutex_unlock(&(db->created_mutex));
			pthread_mutex_unlock(db->last_eat_mutex + idx);
			break ;
		}
		pthread_mutex_unlock(db->last_eat_mutex + idx);
	}
}
