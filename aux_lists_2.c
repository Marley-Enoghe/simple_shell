#include "main.h"

/**
 * add_rvar_node - For adding a variable at the end
 * of a r_var list.
 * @head:The head of the linked list.
 * @lvar: The length of the variable.
 * @val: The value of the variable.
 * @lval: The length of the value.
 * Return: The address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temps;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temps = *head;

	if (temps == NULL)
	{
		*head = new;
	}
	else
	{
		while (temps->next != NULL)
			temps = temps->next;
		temps->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - For freeing a r_var list
 * @head:The head of the linked list.
 * Return: None.
 */
void free_rvar_list(r_var **head)
{
	r_var *temps;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temps = curr) != NULL)
		{
			curr = curr->next;
			free(temps);
		}
		*head = NULL;
	}
}
