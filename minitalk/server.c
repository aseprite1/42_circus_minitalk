/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:08:34 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/27 21:48:04 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	get_signal(int sig)
{	
	static char	c;
	static char	bit;

	if (sig == SIGUSR1)
	{
		if (bit != 0)
			c = c << 1;
		bit++;
	}
	else if (sig == SIGUSR2)
	{
		if (bit)
			c = c << 1;
		c++;
		bit++;
	}
	if (bit == 8)
	{
		if (bit != 0)
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{	
	write(1, "PID : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, (void *)get_signal);
	signal(SIGUSR2, (void *)get_signal);
	while (1)
		pause();
}
