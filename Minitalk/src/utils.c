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

char    *first_char(char c)
{
    char *msg;

    msg = malloc(sizeof(char) * 1 + 1);
    msg[0] = c;
    msg[1] = '\0';
    return(msg);
}

//  Funtion to add a char to the message
char    *ft_addchar(char *str, char c)
{
    char *msg;

    if (!str)
        return(first_char(c));
    int str_len;
    str_len = ft_strlen(str);
    msg = malloc(sizeof(str_len) + 2);
    msg = ft_substr(str, 0, str_len);
    free(str);
    msg[str_len + 1] = c;
    msg[str_len + 2] = '\0';
    return (msg);
}

//  Function that is called if something unexpected happens
void    error_occurrence(void)
{
    ft_printf("Error: Invalid use of parameters\n");
    ft_printf("Correct usage: ./client <Server's PID> <Message>\n");
    exit(1);
}

//  Free the memory of the message string in case of error
void    error_free(char *str)
{
    if (str)
        free(str);
    ft_printf("Error\n");
    exit(1);
}

//  Prints the message received from the client
void    print_msg(char *msg)
{
    ft_putstr_fd(msg, 1);
    free(msg);
}