#include "minitalk.h"

static char	*ft_strcharjoin(char *s1, char c)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
	{
		free (s1);
		return (NULL);
	}
	else
	{
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
		*(ptr + ft_strlen(s1)) = c;
		*(ptr + ft_strlen(s1) + 1) = '\0';
		return (ptr);
	}
}

void	write_char(char *str, t_msg	g_msg)
{
	if (g_msg.c)
	{
		if (g_msg.j == 0)
		{
			str = malloc (sizeof(char) * (2));
			if (!str)
				ft_errexit("malloc failed");
			str[0] = g_msg.c;
			str[1] = '\0';
		}
		else
		{
			str = ft_strcharjoin(str, g_msg.c);
			if (!str)
				ft_errexit("malloc failed");
		}
	}
	if (!g_msg.c)
	{
		str = ft_strcharjoin(str, '\n');
		if (!str)
			ft_errexit("malloc failed");
		str = ft_strcharjoin(str, '\0');
		if (!str)
			ft_errexit("malloc failed");
		ft_putstr_fd(str, 1);
		free (str);
		kill (g_msg.pid, SIGUSR2);
		g_msg.pid = 0;
	}
	g_msg.c = 0;
	g_msg.i = 0;
	
}