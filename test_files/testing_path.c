#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *pathh = get_path();
	printf("PATH = %s\n", pathh);
	
	char *cmdd = "ls";
	char *full_path = find_in_path(cmdd);
	printf("Full path for %s: %s\n", cmdd, full_path);
	
	return (0);
}
