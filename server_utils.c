#include "minitalk.h"

void	write_char(char *str, t_msg	g_msg)
{
	char *s2;
	if (g_msg.c)
	{
		if (g_msg.j == 0)
		{
			str = malloc(sizeof(char)* 1);
			str[0] = '\0';
		}
		s2 = malloc(sizeof(char)* 2);
		s2[0] = g_msg.c;
		s2[1] = '\0';
		str = gnl_ft_strjoin(str, s2);
		g_msg.j++;
		free(s2);
	}
	if (!g_msg.c)
	{
		str = gnl_ft_strjoin(str, "\n");
		ft_putstr_fd(str, 1);
		free (str);
		kill (g_msg.pid, SIGUSR2);
		g_msg.pid = 0;
		g_msg.j= 0;
	}
	g_msg.c = 0;
	g_msg.i = 0;
}