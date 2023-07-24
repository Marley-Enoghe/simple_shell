#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *strrr = "Hello, world!";
	char *strrr2;
	printf("%s\n", strrr);

	printf("Length of string: %d\n", _strlen(strrr));

	char *coppy = _strcpy(strrr, strrr2);
	printf("Copy of string: %s\n", coppy);
	

	char *catt = _strcat(strrr2, " This is a test.");
	printf("Concatenated string: %s\n", catt);
	

	char *dupp = _strdup(strrr2);
	printf("Duplicate of string: %s\n", dupp);
	

	char *string = _strstr(strrr2, "world");
	printf("Substring: %s\n", string);

	return (0);
}
