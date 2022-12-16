#include "shell.h"
#include "prompt.h"
#include "scanner.h"

/**
 * main - a program to read eval print loop from stdin
 *
 * @ac: number of command line args
 * @av: array of command line args
 *
 * Return: SUCCESS(0) or FAILURE(-1)
 */
int main(int ac, char **av)
{
	char *cmdline = NULL;
	smbtable_t *info = NULL;

	(void)ac;

	do {
		print_prompt1();
		cmdline = read_cmd();

		if (cmdline == NULL || strcmp(cmdline, "exit\n") == 0)
		{
			break;
		}
		if (cmdline[0] == '\0' || strcmp(cmdline, "\n") == 0)
		{
			continue;
		}

		info = parse(cmdline);
		if (info == NULL)
		{
			continue;
		}
		executor(info, av[0]);
		free(cmdline);
		free_info(info);
	} while (1);

	free(cmdline);
	exit(EXIT_SUCCESS);
}
