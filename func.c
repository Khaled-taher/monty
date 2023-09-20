#include <monty.h>

/**
 * func - start of code
 * @lineptr: line that has opcode and argument
 * @stak: pointer of stack
 * @num: number of lines
 * @f: pointer to file 
 *
 * Return: nothhing
 */
void func(char *lineptr, stack_t **stak, unsigned int num, FILE *f)
{
	instruction_t inst[] = {
			{"pall", _pall},
			{"push", _push},
			{"pop", _pop},
			{"pint", _pint},
			{"add", _add},
			{"swap", _swap},
			{"sub", _sub},
			{"nop", _nop},
			{"mul", _mul},
			{"div", _div},
			{"mod", _mod},
			{"pchar", _pchar},
			{"pstr", _pstr},
			{"rotr", _rotr},
			{"rotl", _rotl},
			{"stack", _stack},
			{"queue", _queue},
			{NULL, NULL}
			};
	unsigned int i = 0;
	char *op;

	op = strtok(lineptr, " \n\t");
	if (op && op[0] == '#')
		return (0);

	while (inst[i].opcode && op)
	{
		if (strcmp(op, inst[i].opcode) == 0)
		{	inst[i].f(stak, counter);
			return (0);
		}
		i++;
	}
	if (op && inst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		free_stak(*stak);
		free(lineptr);
		fclose(f);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
* free_stak - free list
* @head: head to list
*/
void free_stak(stack_t *head)
{
	stack_t *h;

	h = head;
	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
