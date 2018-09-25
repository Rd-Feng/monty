#include "monty.h"
/**
 * add - add first two elements in stack, remove them, and push result to stack
 * @stack: address of stack
 * @line_number: line number of current processing input
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (state->size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	delete_dnodeint_at_index(stack, 0);/* delete first node */
	delete_dnodeint_at_index(stack, 0);/* delete second node */
	add_dnodeint(stack, sum);
	state->ln--;
}
