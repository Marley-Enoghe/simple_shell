#include "../shell.h"

int main(void)
{
	char *args1s[] = {"exit", "0", NULL};
	char *argss2[] = {"exit", "123", NULL};

	/* Test exit with no arguments */
	shell_exit(argss1);
	/* should exit the shell with status code 0 */

	/* Test exit with argument */
	shell_exit(argss2);
	/* should exit the shell with status code 123 */

	return (0);
}
