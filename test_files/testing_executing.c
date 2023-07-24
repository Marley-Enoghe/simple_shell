#include "../shell.h"
#include <stdio.h>

int main(void)
{
	printf("Testing execute function...\n");
	char *inpuut = get_input();
	char **argss = tokenize_input(inpuut);

	execute(argss);
	
	free(inpuut);
	free_tokens(argss);
	return (0);
}
