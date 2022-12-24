/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:40:39 by tkong             #+#    #+#             */
/*   Updated: 2022/12/24 09:40:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sleeping_(t_db *db);
static void	loop_(t_db *db, pid_t pid);

void	sleeping(t_db *db)
{
	pid_t	pid;

	pid = fork();
	if (pid)
		loop_(db, pid);
	else
		sleeping_(db);
}

static void	sleeping_(t_db *db)
{
	ft_usleep(db->common.sleep);
	exit(0);
}

static void	loop_(t_db *db, pid_t pid)
{
	while (TRUE)
	{
		if (waitpid(pid, NULL, WNOHANG))
			break ;
		if (ft_utime() - db->last_eat > db->common.life)
		{
			kill(pid, SIGTERM);
			exit(db->num);
		}
		ft_usleep(1000);
	}
	sem_wait(db->print);
	printf("%llu %d is thinking\n",
		ft_utom(ft_utime() - db->common.start), db->num);
	sem_post(db->print);
	db->last_change = ft_utime();
}
