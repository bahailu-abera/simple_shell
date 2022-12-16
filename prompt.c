#include "prompt.h"
#include <stdio.h>

/**
 * print_prompt1 - prompts the user for a new command
 *
 * Return: void
 */
void print_prompt1(void)
{
	char *prompt = "#cisfun$ ";

	write(1, prompt, 9);
}

/**
 * print_prompt2 - prompts the user for a multi line command
 *
 * Return: void
 */
void print_prompt2(void)
{
	char *prompt = "> ";

	write(1, prompt, 2);
}
