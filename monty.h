#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/**
 * struct info_s - vars -arguments, file of operation, line pointer
 * @ar: value
 * @f: pointer to monty file
 * @lineptr: line content
 * @flag: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct info_s
{
	char *ar;
	FILE *f;
	char *lineptr;
	int flag;
}  info_t;
extern info_t info;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int func(char *lineptr, stack_t **stak, unsigned int num, FILE *f);
void free_stak(stack_t *head);
void _add(stack_t **stak, unsigned int num);
void _div(stack_t **stak, unsigned int num);
void _mod(stack_t **stak, unsigned int num);
void _sub(stack_t **stak, unsigned int num);
void _mul(stack_t **stak, unsigned int num);
void _pop(stack_t **stak, unsigned int num);
void _pint(stack_t **stak, unsigned int num);
void _swap(stack_t **stak, unsigned int num);
void _pchar(stack_t **stak, unsigned int num);
void _pstr(stack_t **stak, unsigned int num);
void _push(stack_t **stak, unsigned int num);
void _addnod(stack_t **stak, int intgr);
void _addq(stack_t **stak, int intgr);
void _pall(stack_t **stak, unsigned int num);
void _rotl(stack_t **stak, unsigned int num);
void _rotr(stack_t **stak, unsigned int num);
void _queue(stack_t **stak, unsigned int num);
void _stack(stack_t **stak, unsigned int num);
void _nop(stack_t **stak, unsigned int num);

#endif /*MONTY*/
