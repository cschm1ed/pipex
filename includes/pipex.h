/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:14:45 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/16 17:59:14 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_fileds
{
	int	infile;
	int	outfile;
	int	pipe[2];
}	t_filedes;

typedef struct s_cmds
{
	char	**paths;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1;
	char	**cmd2;
}	t_cmds;

typedef struct s_pids
{
	int	pid_cmd1;
	int	pid_cmd2;
}	t_pids;

int		execute_cmd1(t_pids *pids, t_filedes *fds, t_cmds *cmds, char **env);
int		execute_cmd2(t_pids *pids, t_filedes *fds, t_cmds *cmds, char **env);
void	close_fds(t_filedes *fds);

// wrappers
int		dup2_safe(int oldfd, int newfd);
int		close_safe(int fd);
int		fork_safe(t_cmds *cmds, t_filedes *fds);

// utils
int		fds_init(t_filedes *fds, char **argv);
int		cmds_init(char **argv, char **env, t_cmds *cmds);
char	**get_paths(char **env);
char	*command_path(char *cmd, char **paths);

void	zero_structs(t_cmds *cmds, t_filedes *fds);
void	free_str_array(char ***array);
void	free_cmds(t_cmds *cmds);
void	close_fds(t_filedes *fds);
void	try_cleanup(t_filedes *fds, t_cmds *cmds);

#endif
