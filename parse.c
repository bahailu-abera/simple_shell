#include "shell.h"
#include <ctype.h>

/**
 * countargv - countes the number of command line arguments
 *
 * @line: a command line input from stdin
 *
 * Return: number of tokens (seprated by space
 */
int countargv(char *line)
{
	int ac = 0;
	int flag = 1;

	while (isspace(*line))
		line++;
	while (*line)
	{
		if (flag == 1)
			ac++;
		flag = 0;
		while (isspace(*line))
			line++, flag = 1;
		if (!flag)
			line++;
	}

	return (ac);
}

/**
 * parse - parses the command line and builts a symbol table
 *
 * @line: the command line to be parsed
 *
 * Return: the symbol table with the command and command line args
 */
smbtable_t *parse(char *line)
{
	char **argv;
	int ac, index;
	smbtable_t *info;
	char *token;
	char *cmdline = line;

	ac = countargv(cmdline);
	if (ac == 0)
		return (NULL);
	argv = malloc(sizeof(char *) * ac + 1);
	if (argv == NULL)
	{
		free(argv);
		free(line);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	index = 0;
	token = strtok(cmdline, " \n\t");
	while (token != NULL)
	{
		argv[index++] = strdup(token);
		token = strtok(NULL, " \n\t");
	}

	argv[index] = NULL;
	info = malloc(sizeof(smbtable_t));
	if (info == NULL)
	{
		free_argv(argv);
		free(line);
		free(info);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	info->command = argv[0];
	info->argv = argv;

	return (info);
}
