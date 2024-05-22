/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:59:50 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/22 13:38:36 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_msg(int pid, char *msg)
{
    static int bits;
    int i;

    i = 0;
    bits = 7;
    while (msg[i] != '\0')
    {
        while (bits >= 0)
        {
            if (msg[i] << bits & 1)
            {
                printf("%d", msg[i] >> bits);
                kill(pid, SIGUSR1);
            }
            else if (msg[i] << bits & 0)
            {
                printf("%d", msg[i] >> bits);
                kill(pid, SIGUSR2);
            }
            bits--;
        }
        bits = 7;
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    if (argc != 3 || !argv[1][0] || !argv[2][0])
        error_occurrence();
    i = -1;
    pid = ft_atoi(argv[1]);
    while (argv[1][++i])
        if (!ft_isdigit(argv[1][i]))
            error_occurrence();
    send_msg(pid, argv[2]);
}
