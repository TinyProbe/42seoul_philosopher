/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:36:48 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_i32	main(t_i32 ac, t_i8 **av)
{
	t_db	db;

	memset(&db, 0, sizeof(db));
	if (ac < 5 || ac > 6 || init(&db, ac, av))
	{
		write(2, "Invalid Arguments.\n", 19);
		exit(-1);
	}
	exec(&db);
	exit(0);
}
