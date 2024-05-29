/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:04 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/29 17:11:17 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bit(int signal)
{
	static int	bits;
	static char	c;

	if (signal == SIGUSR1)
		c |= (1 << bits);
	else if (signal == SIGUSR2)
		c &= ~(1 << bits);
	if (++bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	signal(SIGINT, exit);
	if (argc != 1 || !argv)
		exit(1);
	ft_printf("---Starting Server---\nServer's PID Number: ");
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
	{
		pause();
	}
}
