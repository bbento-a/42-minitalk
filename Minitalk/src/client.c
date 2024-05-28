/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:59:50 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/28 18:25:19 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *msg)
{
	int	bits;
	int	i;

	i = 0;
	bits = 0;
	while (msg[i] != '\0')
	{
		while (bits < 8)
		{
			if ((msg[i] >> bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bits++;
		}
		bits = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		error_occurrence();
	i = -1;
	while (argv[1][++i])
		if (!ft_isdigit(argv[1][i]))
			error_occurrence();
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	send_msg(pid, "\n");
}
