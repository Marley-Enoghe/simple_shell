#include "../shell.h"

int main(void)
{
	char *inpuuut_str;

	while (1)
	{
		inpuuut_str = get_line();
		if (inpuuut_str == NULL)
		{
			perror("my_getline");
			exit(EXIT_FAILURE);
		}

		if (strcmp(inpuuut_str, "exit") == 0)
			break;

		printf("You entered: %s\n", inpuuut_str);
		free(inpuuut_str);
	}

	printf("Goodbye!\n");
	return (0);
}
