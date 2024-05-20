/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:04 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/20 13:09:00 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    get_bit(int signal)
{
    static int  bits; // bit shifter posistion
    static int  c; // bit storage
    
    bits = 0;
    if (signal == 1)
        c = 1 << bits;
    if (bits++ == 7)
    {
        write(1, &c, 1);
        bits = 0;       
    }
}

int main(int argc, char **argv)
{
    // Starting the server message
    if (argc != 1 || !argv)
        exit(1);
    ft_printf("---Starting Server---\nServer's PID Number: ");
    ft_putnbr_fd(getpid(),1);
    write(1, "\n", 1);

    // Setting up signal handlers
    signal(SIGUSR1, get_bit);
    signal(SIGUSR2, get_bit);

    // Loop for the process to run
    while(1)
    {
        pause();
    }
}