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

static void	waiting(t_db *db);

void	exec(t_db *db)
{
	pid_t pid;

	while (++(db->num) < db->common.nop)
	{
		pid = fork();
		if (!pid)
			break;
	}
	if (!pid)
		schedule(db);
	else
		waiting(db);
}

static void	waiting(t_db *db)
{
	sem_t	*sem;

	sem = sem_open("/fork", O_CREAT | O_EXCL, S_IRWXG, db->common.nop);
	while (db->num--)
		waitpid(-1, NULL, 0);
	sem_close(sem);
	sem_unlink("/fork");
}
