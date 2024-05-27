/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:04 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/22 12:17:11 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// 1 global variable used in server file for
// int gmsg_len;

// void   get_msg_len(int signal)
// {
//     static int  len;
//     static int  bits;

//     bits = 0;
//     if (signal == 1)
//         len = 1 << bits;
//     if (bits++ == 7)
//     {
//         gmsg_len = len;
//         len = 0;
//         bits = 0;
//         ft_printf("lenght: %i\n", gmsg_len);
//     }
// }

void get_bit(int signal)
{
    static int bits = 0; // bit shifter posistion
    static int c = 0;    // bit storage
    // static int i;
    // static char *msg;

    // i = 0;
    // msg = 0;
    if (signal == SIGUSR1)
        c |= (1 << bits);
    else if (signal == SIGUSR2)
        c &= (0 << bits);
    bits++;
    if (bits == 8)
    {
        write(1, &c, 1);
        // ft_addchar(msg, c);
        bits = 0;
        c = 0;
    }
}

int main(int argc, char **argv)
{
    // Starting the server message
    if (argc != 1 || !argv)
        exit(1);
    ft_printf("---Starting Server---\nServer's PID Number: ");
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);

    // Setting up signal handlers
    signal(SIGUSR1, get_bit);
    signal(SIGUSR2, get_bit);

    // Loop for the process to run
    while (1)
    {
        pause();
    }
}