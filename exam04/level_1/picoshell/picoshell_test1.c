#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int		prev_fd;
	int		pipefd[2];
	int		i;
	int		ret;
	int		status;
	pid_t	pid;

	prev_fd = -1;
	i = 0;
	ret = 0;
	if (!cmds || !cmds[0])
		return (1);
	while (cmds[i])
	{
		if (cmds[i + 1])
		{
			if (pipe(pipefd) == -1)
			{
				ret = 1;
				break ;
			}
		}
		else
		{
			pipefd[0] = -1;
			pipefd[1] = -1;
		}
		pid = fork();
		if (pid < 0)
		{
			if (pipefd[0] != -1)
				close(pipefd[0]);
			if (pipefd[1] != -1)
				close(pipefd[1]);
			ret = 1;
			break ;
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
		}
	}
}

