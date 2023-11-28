/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:51:03 by sde-silv          #+#    #+#             */
/*   Updated: 2023/11/04 16:51:06 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

# define int BUSY = 1;
# define int FREE = 0;

typedef struct s_msg
{
	char			c;
	int				i;
	int 			pid;
	int 			status;
}					t_msg;

#endif
