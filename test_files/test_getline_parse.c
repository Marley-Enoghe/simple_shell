#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *inpuut = "ls -l /usr/bin";
	char **toookens = tokenize_input(inpuut);

	_puts("Testing prompt function...\n");
	for (int i = 0; toookens[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i, toookens[i]);
	}

	free_tokens(toookens);

	printf("Testing get_input function...\n");
	char *inpuut = get_input();
	printf("Input: %s\n", inpuut);
        free(inpuut);

	return (0);
}
