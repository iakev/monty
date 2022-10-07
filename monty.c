#include "monty.h"
char **argv;
/**
 * main - entry point to our program that interpretes monty byte code
 *
 * @ac: interger representing the command line arguments counter
 * @av: container/vector containing command line arguments
 *
 * Return: Nothing
 */
int main(int ac, char **av)
{
	FILE *fp;
	ssize_t line_sz = 0;
	char *lineptr = NULL, *token = NULL;
	size_t n = 0;
	unsigned int line_count = 0;
	stack_t *head = NULL;

	if (ac != 2)
		usage_error();
	fp = fopen(av[1], "r");
	if (fp == NULL)
		open_error(av[1]);
	while (1)
	{
		line_count++;
		line_sz = getline(&lineptr, &n, fp);
		if (line_sz == -1)
			break;
		token = strtok(lineptr, "\n");
		argv = input_tokenizer(token);
		execute_opcode(line_count, &head, argv);
	}
	fclose(fp);
	free(lineptr);
	free_argv(argv);
	/* free created linked list here */
	return (0);
}
/**
 * usage_error - error handling on incorrect calling of program
 *
 * Return: Nothing
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error - error handling on failuret to open file
 *
 * @str: name of file failed to open
 *
 * Return: Nothing
 */
void open_error(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}
/**
 * opcode_error - error handling on invalid instruction
 *
 * @line_number: line number where invalid instruction is
 * @str: name of invalid instruction
 *
 * Return: Nothing
 */
void opcode_error(unsigned int line_number, char *str)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number
		, str);
	free_argv(argv);
	exit(EXIT_FAILURE);
}
/**
 * input_tokenizer - Separate commands and their arguments
 * @str: Commandline with optional arguments
 * Return: Nothing
 */
char **input_tokenizer(char *str)
{
	int count = 1;
	size_t j = 0;
	char *token = NULL, *ptr = NULL;
	char **arg = NULL;

	if (str == NULL)
		return (NULL);
	while (str[j])
	{
		if (str[j] != ' ')
			break;
		j++;
	}
	if (j == strlen(str))
		return (argv);
	ptr = _strdup(str);
	token = strtok(ptr, " ");
	while (token)
	{
		token = strtok(NULL, " ");
		count++;
	}
	arg = malloc(sizeof(*argv) * count);
	if (arg == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " ");
	j = 0;
	while (token)
	{
		arg[j] = NULL;
		arg[j] = _strdup(token);
		j++;
		token = strtok(NULL, " ");
	}
	arg[j] = NULL;
	free(ptr);
	return (arg);
}
