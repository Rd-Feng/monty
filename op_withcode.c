#include "monty.h"
int isInt(char *s);
/**
 * push - push a element to stack/queue
 * @stack: address of stack
 * @line_number: line number of current processing input
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!state->argument || !isInt(state->argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	if (state->mode == MOD_STK)
		add_dnodeint(stack, atoi(state->argument));
	else
		add_dnodeint_end(stack, atoi(state->argument));
	state->size++;
}
/**
 * isInt - check if a string is integer
 * @s: string
 *
 * Return: 0 if not integer, 1 otherwise
 */
int isInt(char *s)
{
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		s++;
	}
	return (1);
}
