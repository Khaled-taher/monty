#include "monty.h"

/**
  *_rotl - rotating the stack to top
  *@stak: pointer to head of stack
  *@num: number of line
  *Return: nothing
 */
void _rotl(stack_t **stak, unsigned int num)
{
	stack_t *h, *a;

	h = *stak;
	(void) num;
	if (*stak == NULL || (*stak)->next == NULL)
	{
		return;
	}
	a = (*stak)->next;
	a->prev = NULL;
	while (h->next != NULL)
	{
		h = h->next;
	}
	(*stak)->next = NULL;
	h->next = *stak;
	(*stak)->prev = h;
	(*stak) = a;
}

/**
  *_rotr - rotates the stack to the bottom
  *@stak: pointer to head of stack
  *@num: number of line
  *Return: nothing
 */
void _rotr(stack_t **stak, unsigned int num)
{
	stack_t *h;

	h = *stak;
	(void) num;
	if (*stak == NULL || (*stak)->next == NULL)
	{
		return;
	}
	while (h->next)
	{
		h = h->next;
	}
	h->next = *stak;
	h->prev->next = NULL;
	h->prev = NULL;
	(*stak)->prev = h;
	(*stak) = h;
}
