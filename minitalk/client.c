/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:05:48 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/30 00:15:53 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		n;
	int		k;

	n = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (s1[n])
	{
		result[n] = s1[n];
		n++;
	}
	k = n;
	n = 0;
	while (s2[n])
	{
		result[k + n] = s2[n];
		n++;
	}
	return (result);
}

long long	ft_atoi(char *str)
{
	long long	result;
	long long	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
	str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str <= '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	send_sig(pid_t pid, char *argv)
{
	char	c;
	int		n;

	while (*argv)
	{
		c = *argv;
		n = 0;
		while (n++ < 8)
		{
			if (c & 128)
			{
				if (kill(pid, SIGUSR2) < 0)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) < 0)
					exit(1);
			}
			c = c << 1;
			usleep(200);
		}
		argv++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "Wrong argument", 15);
		exit(1);
	}
	str = ft_strjoin(argv[2], "\n");
	if (!str)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid > 0)
		send_sig(pid, str);
	else
	{
		write(1, "Wrong PID!", 10);
		exit(1);
	}
	free(str);
	return (0);
}
