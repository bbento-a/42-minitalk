/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:59:50 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/15 12:30:22 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_bit(int )
{}

int main(int argc, char **argv)
{
    int i;

    i = -1;
    if (argc != 3 || !argv[1][0] || !argv[2][0])
        error_occurrence();
    while (argv[1][++i])
        if (!ft_isdigit(argv[1][i]))
            error_occurrence();
    ft_printf("PID SIGUSR1:\n", getpid(SIGUSR1));
    
            
}

void    error_occurrence(void)
{
    ft_printf("Error: Invalid use of parameters\n");
    ft_printf("Correct usage: ./client <Server's PID> <Message>\n");
    exit(1);
}