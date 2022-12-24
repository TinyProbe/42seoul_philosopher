/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:36:39 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exec(t_db *db)
{
	pid_t	pid;
	t_i32	idx;

	db->fork = sem_open(
			"/fork", O_CREAT | O_EXCL, S_IRWXG, db->common.nop);
	db->fork_access = sem_open(
			"/fork_access", O_CREAT | O_EXCL, S_IRWXG, db->common.nop / 2);
	db->print = sem_open(
			"/print", O_CREAT | O_EXCL, S_IRWXG, 1);
	idx = 0;
	while (db->num++ < db->common.nop)
	{
		pid = fork();
		if (!pid)
			break ;
		db->pid[idx++] = pid;
	}
	if (pid)
		loop(db);
	else
		schedule(db);
}
