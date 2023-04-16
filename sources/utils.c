/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:00:18 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/16 18:17:50 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	**paths;
	char	*temp;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	paths = ft_split(env[i] + 5, ":");
	if (!paths)
		return (perror("malloc"), NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (free_str_array(&paths), perror("malloc"), NULL);
		free(paths[i]);
		paths[i] = temp;
		i++;
	}
	return (paths);
}

char	*command_path(t_filedes *fds, t_cmds *cmds, char *cmd, char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd || !*cmd)
		return (ft_printf("pipex: %s: command not found\n", cmd), NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		if (!tmp)
		{
			perror("malloc");
			try_cleanup(fds, cmds);
			exit(1);
		}
		if (access(tmp, F_OK | X_OK) != -1)
			return (tmp);
		free(tmp);
		i ++;
	}
	return (ft_printf("pipex: %s: command not found\n", cmd), NULL);
}

int	cmds_init(char **argv, char **env, t_filedes *fds, t_cmds *cmds)
{
	cmds->paths = get_paths(env);
	if (!cmds->paths)
		return (-1);
	cmds->cmd1 = ft_split(argv[2], " \t\r\f\v");
	if (!cmds->cmd1)
		return (free_cmds(cmds), -1);
	cmds->cmd1_path = command_path(fds, cmds, cmds->cmd1[0], cmds->paths);
	cmds->cmd2 = ft_split(argv[3], " \t\r\f\v");
	if (!cmds->cmd2)
		return (free_cmds(cmds), -1);
	cmds->cmd2_path = command_path(fds, cmds, cmds->cmd2[0], cmds->paths);
	if (!cmds->cmd2_path)
		return (free_cmds(cmds), -1);
	return (0);
}

int	fds_init(t_filedes *fds, char **argv)
{
	if (access(argv[4], F_OK) != -1 && access(argv[4], W_OK) == -1)
		return (ft_printf("pipex: %s: Permission denied\n"), -1);
	fds->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fds->outfile == -1)
		return (close_fds(fds), perror("open"), 1);
	if (access(argv[1], F_OK) == -1)
		return (ft_printf("pipex: %s: No such file or directory\n",
				argv[1]), -1);
	if (access(argv[1], R_OK) == -1)
		return (ft_printf("pipex: %s: permission denied\n"), -1);
	fds->infile = open(argv[1], O_RDONLY);
	if (fds->infile == -1)
		return (perror("open"), -1);
	if (pipe(fds->pipe) == -1)
		return (perror("pipe"), 1);
	return (0);
}
