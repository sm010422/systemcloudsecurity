#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 50

int vul_func(char *str) {
	char buffer[BUF_SIZE];
	unsigned int *framep;

	asm("movl %%ebp, %0" : "=r" (framep));

	printf("Address of buffer[] inside vul_func(): 0x%.8x\n", (unsigned)buffer);
	printf("Frame pointer value inside vul_func(): 0x%.8x\n", (unsigned)framep);

	strcpy(buffer, str); // buffer overflow

	return 1;
}

int main(int argc, char **argv) {
	char input[1000];
	FILE *badfile;
	
	char *myshell = (char *)getenv("MYSHELL");
	if (myshell != NULL) {
		printf("Value of MYSHELL: %s\n", myshell); // /bin/sh
		printf("Address of MYSHELL: 0x%x\n", (unsigned int)myshell);
	}

	badfile = fopen("badfile", "r");
	int length = fread(input, sizeof(char), 1000, badfile);

	printf("Address of input[] inside main(): 0x%x\n", (unsigned)input);
	printf("Input size: %d\n", length);

	vul_func(input);

	printf("Returned properly\n");

	return 1;
}
