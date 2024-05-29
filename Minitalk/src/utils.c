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

void    error_occurrence(void)
{
    ft_printf("Error: Invalid use of parameters\n");
    ft_printf("Correct usage: ./client <Server's PID> <Message>\n");
    exit(1);
}

