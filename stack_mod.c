#include "monty.h"

/**
 * _queue - change to queue mod
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _queue(stack_t **stak, unsigned int num)
{
	info.flag = 1;
	(void)stak;
	(void)num;
}

/**
 * _stack - change to stack mod
 * @stak: pointer to head of stack
 * @num: number of line
 * Return: nothing
*/
void _stack(stack_t **stak, unsigned int num)
{
	info.flag = 0;
	(void)stak;
	(void)num;
}

/**
  *_nop- nothing
  *@stak: pointer to head of stack
  *@num: number of line
  *Return: nothing
 */
void _nop(stack_t **stak, unsigned int num)
{
	(void) stak;
	(void) num;
}

