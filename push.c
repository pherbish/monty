#include "monty.h"
/**
 * op_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void op_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (vline.varg)
	{
		if (vline.varg[0] == '-')
			j++;
		for (; vline.varg[j] != '\0'; j++)
		{
			if (vline.varg[j] > 57 || vline.varg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(vline.file);
			free(vline.vhold);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(vline.file);
		free(vline.vhold);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(vline.varg);
	if (vline.flg == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
