#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char *myshell = (char *)getenv("MYSHELL");

	if (myshell != NULL) {
		printf("Value of MYSHELL: %s\n", myshell); // /bin/sh
		printf("Address of MYSHELL: 0x%x\n", (unsigned int)myshell);
	}

	return 0;
}
