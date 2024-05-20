/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:24:06 by bbento-a          #+#    #+#             */
/*   Updated: 2024/05/20 13:09:55 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


//  Funtion to add a char to the message
// char    *ft_addchar(char *str, char c)
// {
//     char *msg;
//     int str_len = ft_strlen(str);

//     if(!str)
//         msg = malloc(sizeof(char) + 1);
//     msg = malloc(sizeof(str_len) + 2);
//     msg = ft_substr(str, 0, str_len);
//     msg[str_len + 1] = c;
//     msg[str_len + 2] = '\0';
//     free(str);
//     return (msg);
// }

//  Function that is called if something unexpected happens
void    error_occurrence(void)
{
    ft_printf("Error: Invalid use of parameters\n");
    ft_printf("Correct usage: ./client <Server's PID> <Message>\n");
    exit(1);
}