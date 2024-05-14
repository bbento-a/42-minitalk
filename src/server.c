/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:04 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/14 13:19:13 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    // Starting the server message
    if (argc != 1 || !argv)
        exit(1);
    ft_printf("---Starting Server---\nServer's PID Number: ");
    ft_putnbr_fd(getpid(),1);
    write(1, "\n", 1);

    // Working process with signals
    while(1)
    {
        signal
    }
}