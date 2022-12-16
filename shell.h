#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * struct symboltable - symbol table for a single command line
 * @command: the command to be exucuted
 * @argv: the arguments for the command to be passed
 */
typedef struct symboltable
{
	char *command;
	char **argv;
} smbtable_t;

smbtable_t *parse(char *line);
void executor(smbtable_t *info, char *cmd);
void free_info(smbtable_t *info);
void free_line(char *line);
void free_argv(char **argv);

extern char **environ;
#endif
