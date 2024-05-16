/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:04 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/15 12:24:05 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    print_bit(int signal)
{
    if (signal == SIGUSR1)
        printf("Received SIGUSR1\n");
}

int main(int argc, char **argv)
{
    // Starting the server message
    if (argc != 1 || !argv)
        exit(1);
    ft_printf("---Starting Server---\nServer's PID Number: ");
    ft_putnbr_fd(getpid(),1);
    write(1, "\n", 1);

    // Setting up signal
    signal(SIGUSR1, print_bit);

    // Loop for the process to run
    while(1)
    {
        pause();
    }
}