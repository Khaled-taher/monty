#include "monty.h"
/**
 * _push - add node to the stack
 * @stak: pointer to head of stack
 * @num: number of line in file
 * Return: nothing
*/
void _push(stack_t **stak, unsigned int num)
{
	int i = 0, intgr, flg = 0;

	if (!info.ar)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(info.f);
		free(info.lineptr);
		free_stak(*stak);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (info.ar[0] == '-')
			i++;
		for (; info.ar[i] != '\0'; i++)
		{
			if (info.ar[i] > 57 || info.ar[i] < 48)
				flg = 1;
		}
		if (flg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(info.f);
			free(info.lineptr);
			free_stak(*stak);
			exit(EXIT_FAILURE);
		}
	}
	intgr = atoi(info.ar);
	if (info.flag == 1)
		_addq(stak, intgr);
	else
		_addnod(stak, intgr);
}

/**
 * _addnod - to add a node in front of stack
 * @stak: pointer to head
 * @intgr: a value to be added
 * Return: nothing
*/
void _addnod(stack_t **stak, int intgr)
{
	stack_t *new, *h;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	h = *stak;
	if (h)
		h->prev = new;
	new->prev = NULL;
	new->next = *stak;
	new->n = intgr;
	*stak = new;
}

/**
 * _addq - to add a node in the end of stack
 * @intgr: a value to be add
 * @stak: head of the stack
 * Return: nothing
*/
void _addq(stack_t **stak, int intgr)
{
	stack_t *new, *h;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = intgr;
	new->next = NULL;
	h = *stak;
	if (h)
	{
		while (h->next)
			h = h->next;
	}
	if (!h)
	{
		*stak = new;
		new->prev = NULL;
	}
	else
	{
		h->next = new;
		new->prev = h;
	}
}

/**
 * _pall - prints the stack
 * @stak: pointer to head of stack
 * @num: numer of line
 * Return: nothing
*/
void _pall(stack_t **stak, unsigned int num)
{
	stack_t *h;
	(void)num;

	h = *stak;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

