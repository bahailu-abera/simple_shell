#include "shell.h"

/**
 * free_info - frees the memory allocated for symbol table
 *
 * @info: the info table
 *
 * Return: void
 */
void free_info(smbtable_t *info)
{
	int i = 0;

	if (info == NULL)
		return;

	while (info->argv[i] != NULL)
		free(info->argv[i]), i++;
	free(info);
}

/**
 * free_line - frees a memory allocated for a line
 *
 * @line:  a pointer to a char
 *
 * Return: void
 */
void free_line(char *line)
{
	if (line == NULL)
		return;
	free(line);
	line = NULL;
}

/**
 * free_argv - frees a memory allocated for array of strings
 *
 * @argv: array of args
 *
 * Return: void
 */
void free_argv(char **argv)
{
	int index = 0;

	while (argv[index] != NULL)
		free(argv[index]), index++;
	free(argv);
}
