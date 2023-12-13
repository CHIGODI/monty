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
int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc == 0 || argc > 2)
	{
		write(2, "USAGE: monty file", 17);
		exit(EXIT_FAILURE);
	}
	fp = open(argv[1] , O_RDONLY);
	if (fp == NULL)
	{
		write(2, "Error: Can't open file <file>", 29);
		exit(EXIT_FAILURE);
	}
	
