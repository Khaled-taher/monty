#include "monty.h"
/**
 * _pop - printing the top of stack
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _pop(stack_t **stak, unsigned int num)
{
	stack_t *p;

	if (*stak == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	*stak = p->next;
	free(p);
}

/**
 * _pint - printing the top of stack without poping
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _pint(stack_t **stak, unsigned int num)
{
	if (*stak == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stak)->n);
}

/**
 * _swap - swap the top 2 ele of the stack with each other.
 * @stak: pointer to head stack
 * @num: line_number
 * Return: nothing
*/
void _swap(stack_t **stak, unsigned int num)
{
	stack_t *p;
	int a, len = 0;

	p = *stak;
	while (p)
	{
		p = p->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	a = p->n;
	p->n = p->next->n;
	p->next->n = a;
}

/**
 * _pchar - printing char at top ofstack
 * @stak: pointer of head stack
 * @num: number of line
 * Return: nothing
*/
void _pchar(stack_t **stak, unsigned int num)
{
	stack_t *p;

	p = *stak;
	if (!p)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}

/**
 * _pstr - printing string starting at top of stack,
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _pstr(stack_t **stak, unsigned int num)
{
	stack_t *p;
	(void)num;

	p = *stak;
	while (p)
	{
		if (p->n > 127 || p->n <= 0)
		{
			break;
		}
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}
