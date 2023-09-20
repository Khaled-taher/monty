#include "monty.h"

/**
 * _add - add the 2 nodes in the top
 * @stak: pointer to tghe head of stak
 * @num: number of line
 * Return: nothing
*/
void _add(stack_t **stak, unsigned int num)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	a = p->n + p->next->n;
	p->next->n = a;
	*stak = p->next;
	free(p);
}

/**
 * _div - divide the 2 nodes in the top
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _div(stack_t **stak, unsigned int num)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	a = p->next->n / p->n;
	p->next->n = a;
	*stak = p->next;
	free(p);
}

/**
 * _mod - divide the 2 nodes in the top and return reminder
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _mod(stack_t **stak, unsigned int num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	a = p->next->n % p->n;
	p->next->n = a;
	*stak = p->next;
	free(p);
}

/**
 * _sub - subtract the 2 nodes in the top
 * @stak: pointer to the head of stak
 * @num: number of line
 * Return: nothing
*/
void _sub(stack_t **stak, unsigned int num)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	a = p->n - p->next->n;
	p->next->n = a;
	*stak = p->next;
	free(p);
}

/**
 * _mul - subtract the 2 nodes in the top
 * @stak: pointer to the head of stak
 * @num: number of line
 * Return: nothing
*/
void _mul(stack_t **stak, unsigned int num)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	p = *stak;
	a = p->n * p->next->n;
	p->next->n = a;
	*stak = p->next;
	free(p);
}

