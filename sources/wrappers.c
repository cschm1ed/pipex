/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:34:40 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/09 17:54:53 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	dup2_safe(int fd_new, int fd_old)
{
	if (dup2(fd_new, fd_old) == -1)
		return (perror("dup2"), -1);
	return (0);
}

int	fork_safe(t_cmds *cmds, t_filedes *fds)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (try_cleanup(fds, cmds), perror("fork"), -1);
	return (pid);
}

int	close_safe(int fd)
{
	if (close(fd) == -1)
		return (perror("close"), -1);
	return (0);
}
