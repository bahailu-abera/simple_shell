#include "shell.h"

/**
 * executor - a function to fork and execute child process
 *
 * @info: the data to be passed to the child process
 * @cmd: the name of the executable program
 *
 * Return: void
 */
void executor(smbtable_t *info, char *cmd)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		free_info(info);
		exit(-1);
	}
	if (pid == 0)
	{
		if (execve(info->command, info->argv, environ) == -1)
			perror(cmd);
		exit(EXIT_SUCCESS);
	}
	wait(&status);
}
