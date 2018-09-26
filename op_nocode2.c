#include "monty.h"
/**
 * pchar - pring top of stack as char
 * @stack: address of stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (state->size == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
