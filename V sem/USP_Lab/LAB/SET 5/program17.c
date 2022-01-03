#include<stdio.h>
int main(int argc, char* argv[ ])
{
	int i;
	char **ptr;
	extern char **environ;
	for( ptr = environ; *ptr != 0; ptr++ ) /*echo all env strings*/
	printf("%s\n", *ptr);return 0;
}
