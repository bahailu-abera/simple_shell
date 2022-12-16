#include "scanner.h"

/**
 * read_cmd - reads a line from the stdin
 *
 * Return: a string (Succes)
 * NULL on failure
 */
char *read_cmd(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	errno = 0;
	nread = getline(&line, &len, stdin);

	if (nread == -1 && errno == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
