#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (!file || !argv || (type != 'r' && type!= 'w'))
		return (-1);
	status = pipe(pipefd);
	if (status == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
			close(pipefd[1]);
		}
		else
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
		}
		execvp(file, argv);
		exit (1);
	}
	if (type == 'r')
	{
		close(pipefd[1]);
		return (pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		return (pipefd[1]);
	}
}

int main(void)
{
	int		fd;
	int		n;
	char	buff[100];

	fd = ft_popen("cat", (char *const []){"cat", NULL}, 'w');
	write(fd, "abc\n", 4);
	close(fd);

	fd = ft_popen("echo", (char *const []){"echo", "abc", NULL}, 'r');
	n = read(fd, buff, 100);
	write(1, buff, n);
	close(fd);
}
