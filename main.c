#include "monty.h"
info_t *state = NULL;
/**
 * main - entry point of Monty interpreter
 * @argc: argument count
 * @argv: argument strings array
 *
 * Return: 0 on success, exit with status code on failure
 */
int main(int argc, char **argv)
{
	size_t size = BUF_SIZE;
	int i, num_read = 0;
	FILE *fptr = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	state_init();
	do {
		for (i = 0; i < BUF_SIZE; i++)
			state->buffer[i] = 0;
		num_read = getline(&(state->buffer), &size, fptr);
		process_line(state->buffer);
		if (state->op)
			runner();
		state->op = NULL;
		state->argument = NULL;
	} while (num_read != -1);

	fclose(fptr);
	state_clear();
	return (0);
}
