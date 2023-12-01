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

# define MSG_SIZE 60000

typedef struct s_msg
{
	char		c;
	int			i;
	int			pid;
	int 		j;
}				t_msg;

#endif
