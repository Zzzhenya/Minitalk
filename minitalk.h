/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:51:03 by sde-silv          #+#    #+#             */
/*   Updated: 2023/11/28 16:59:51 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_msg
{
	char		c;
	int			i;
	int			pid;
	int			j;
	char 		*str;
}				t_msg;

void	write_char(char *str, t_msg	g_msg);
void	bit_handler(int sig, siginfo_t *info, void *x);

#endif
