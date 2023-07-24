#include "../shell.h"

int main(void)
{
	char *dirc = _getenv("PWD");
	printf("Current directory: %s\n", dirc);

	char *argss[] = {"cd", "..", NULL};
	shell_cd(argss);

	dirc = _getenv("PWD");
	printf("Current directory: %s\n", dirc);

	return 0;
}
