/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:11 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/10/07 14:29:03 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

void	send_signal(char *str, int pid)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		n = 0;
		while (n < 8)
		{
			if (str[i] & 128 >> n)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			n++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_signal(argv[2], pid);
	send_signal("\n", pid);
	return (0);
}
