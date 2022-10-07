#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
extern char **argv;
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
/* main program functionality */
void usage_error(void);
void open_error(char *str);
void opcode_error(unsigned int line_number, char *);
char **input_tokenizer(char *str);
/* memory management */
void free_argv(char **argv);
/* executing opcodes helper and push and pall functions*/
void execute_opcode(int line_number, stack_t **, char **);
/* functions dealing with doubly linked lists */
size_t print_dlistint(stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
/* string manipulation */
char *_strdup(char *str);
#endif /* MONTY_H */
