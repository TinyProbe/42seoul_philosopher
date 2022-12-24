/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:40:42 by tkong             #+#    #+#             */
/*   Updated: 2022/12/24 09:40:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	thinking_(t_db *db);
static void	loop_(t_db *db, pid_t pid);

void	thinking(t_db *db)
{
	pid_t	pid;

	pid = fork();
	if (pid)
		loop_(db, pid);
	else
		thinking_(db);
}

static void	thinking_(t_db *db)
{
	sem_wait(db->fork_access);
	sem_wait(db->fork);
	sem_wait(db->fork);
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
	printf("%llu %d has taken a fork\n",
		ft_utom(ft_utime() - db->common.start), db->num);
	printf("%llu %d has taken a fork\n",
		ft_utom(ft_utime() - db->common.start), db->num);
	printf("%llu %d is eating\n",
		ft_utom(ft_utime() - db->common.start), db->num);
	sem_post(db->print);
	db->last_change = ft_utime();
	db->last_eat = db->last_change;
}
