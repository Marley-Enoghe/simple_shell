#include "../shell.h"

int main(void)
{
	char *argss1[] = {"exit", NULL};
	char *argss2[] = {"env", NULL};
	char *argss3[] = {"setenv", "VAR", "value", NULL};
	char *argss4[] = {"unsetenv", "VAR", NULL};
	char *argss5[] = {"help", NULL};
	char *argss6[] = {"cd",  NULL};
	char *argss7[] = {"ls", NULL};

	check_for_builtin(argss2); 
	check_for_builtin(argss3); 
	check_for_builtin(argss4); 
	check_for_builtin(argss5); 
	check_for_builtin(argss6); 
	check_for_builtin(argss7); 
	
	return (0);
}
