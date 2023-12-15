#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 *
 * Return: 0 always succesfull
 *
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	execute_commands(fp, &stack);

	fclose(fp);
	return (0);
}
