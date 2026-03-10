#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
	int		prev_fd = -1;
	int		pipefd[2];
	int		i = 0;
	int		ret = 0;
	int		status;

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
		pid_t	pid = fork();
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
			{
				if (dup2(prev_fd, 0) == -1)
					exit(1);
			}
			if (cmds[i + 1] != NULL)
			{
				if (dup2(pipefd[1], 1) == -1)
					exit(1);
			}
			if (prev_fd != -1)
				close(prev_fd);
			if (cmds[i + 1] != NULL)
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_fd != -1)
			close(prev_fd);
		if (cmds[i + 1] != NULL)
		{
			close(pipefd[1]);
			prev_fd = pipefd[0];
		}
		else
		{
			prev_fd = -1;
		}
		i++;
	}
	if (prev_fd != -1)
		close(prev_fd);
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status) == 0 || WEXITSTATUS(status) != 0)
			ret = 1;
	}
	return (ret);
}

#include <stdio.h>
int main(void)
{
    char *cmd1[] = {"/bin/ls", "level-1", NULL};
    char *cmd2[] = {"/usr/bin/grep", "picoshell", NULL};
    char **cmds[] = {cmd1, cmd2, NULL};

    int result = picoshell(cmds);
    printf("picoshell returned %d\n", result);
    return 0;
}
