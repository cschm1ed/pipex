/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:32:57 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/16 18:07:42 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_filedes	fds;
	t_cmds		cmds;
	t_pids		pids;
	int			status;

	zero_structs(&cmds, &fds);
	if (argc != 5)
		return (ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n"), 1);
	if (fds_init(&fds, argv) == -1 || cmds_init(argv, env, &cmds) == -1)
		return (try_cleanup(&fds, &cmds), 1);
	if (execute_cmd1(&pids, &fds, &cmds, env) == -1)
		return (try_cleanup(&fds, &cmds), 1);
	if (execute_cmd2(&pids, &fds, &cmds, env) == -1)
		return (try_cleanup(&fds, &cmds), 1);
	try_cleanup(&fds, &cmds);
	waitpid(pids.pid_cmd1, &status, 0);
	waitpid(pids.pid_cmd2, &status, 0);
	return (status >> 8);
}

int	execute_cmd2(t_pids *pids, t_filedes *fds, t_cmds *cmds, char **env)
{
	pids->pid_cmd2 = fork_safe(cmds, fds);
	if (pids->pid_cmd2 == -1)
		return (-1);
	else if (pids->pid_cmd2 == 0)
		return (0);
	if (dup2_safe(fds->outfile, STDOUT_FILENO) == -1
		|| close_safe(fds->pipe[1]) == -1
		|| close_safe(fds->outfile) == -1
		|| dup2_safe(fds->pipe[0], STDIN_FILENO) == -1
		|| close_safe(fds->pipe[0]) == -1)
		return (-1);
	if (execve(cmds->cmd2_path, cmds->cmd2, env) == -1)
		return (perror("execve"), -1);
	return (0);
}

int	execute_cmd1(t_pids *pids, t_filedes *fds, t_cmds *cmds, char **env)
{
	if (!cmds->cmd1_path)
	{
		if (close_safe(fds->infile) == -1
			|| close_safe(fds->pipe[1]) == -1)
			return (-1);
		return (0);
	}
	pids->pid_cmd1 = fork_safe(cmds, fds);
	if (pids->pid_cmd1 == -1)
		return (-1);
	else if (pids->pid_cmd1 > 0)
		return (0);
	if (dup2_safe(fds->infile, STDIN_FILENO) == -1
		|| close_safe(fds->pipe[0]) == -1
		|| close_safe(fds->infile) == -1
		|| dup2_safe(fds->pipe[1], STDOUT_FILENO) == -1
		|| close_safe(fds->pipe[1]) == -1)
		return (-1);
	if (execve(cmds->cmd1_path, cmds->cmd1, env) == -1)
		return (perror("execve"), 1);
	return (0);
}
