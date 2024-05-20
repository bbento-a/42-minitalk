/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:59:50 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/20 12:39:14 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//  Function to convert bits to a char
char    bits_tochar(char *bits)
{
    
}

void    send_msg(int pid, char *msg)
{
    int i;

    while (msg[i] != '\0')
    {
        bit__tochar();
        ft_addchar(msg, msg[i]);
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = -1;
    if (argc != 3 || !argv[1][0] || !argv[2][0])
        error_occurrence();
    while (argv[1][++i])
        if (!ft_isdigit(argv[1][i]))
            error_occurrence();
    
    send_msg(getpid, argv[2]);
}
