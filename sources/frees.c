/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:03:28 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 15:38:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(t_filedes *fds)
{
	if (fds->infile != -1)
	{
		close(fds->infile);
		fds->infile = -1;
	}
	if (fds->outfile != -1)
	{
		close(fds->outfile);
		fds->outfile = -1;
	}
	if (fds->pipe[0] != -1)
	{
		close(fds->pipe[0]);
		fds->pipe[0] = -1;
	}
	if (fds->pipe[1] != -1)
	{
		close(fds->pipe[1]);
		fds->pipe[1] = -1;
	}
}

void	free_cmds(t_cmds *cmds)
{
	if (cmds->paths)
	{
		free_str_array(&cmds->paths);
		cmds->paths = NULL;
	}
	if (cmds->cmd1_path)
	{
		free(cmds->cmd1_path);
		cmds->cmd1_path = NULL;
	}
	if (cmds->cmd2_path)
	{
		free(cmds->cmd2_path);
		cmds->cmd2_path = NULL;
	}
	if (cmds->cmd1)
	{
		free_str_array(&cmds->cmd1);
		cmds->cmd1 = NULL;
	}
	if (cmds->cmd2)
	{
		free_str_array(&cmds->cmd2);
		cmds->cmd2 = NULL;
	}
}

void	free_str_array(char ***array)
{
	int	i;

	i = 0;
	if (*array == NULL)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = 0;
		i++;
	}
	free(*array);
}

void	try_cleanup(t_filedes *fds, t_cmds *cmds)
{
	close_fds(fds);
	free_cmds(cmds);
}

void	zero_structs(t_cmds *cmds, t_filedes *fds)
{
	fds->infile = -1;
	fds->outfile = -1;
	fds->pipe[0] = -1;
	fds->pipe[1] = -1;
	cmds->paths = NULL;
	cmds->cmd1 = NULL;
	cmds->cmd2 = NULL;
	cmds->cmd1_path = NULL;
	cmds->cmd2_path = NULL;
}
