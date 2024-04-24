//环境变量
#include <stdio.h>

int main(void)
{
	extern char** environ;
	char** pp;
	for(pp = environ; *pp != NULL; pp++)
	{
		printf("%s\n", *pp);
	}

	return 0;
}
