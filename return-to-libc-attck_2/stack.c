#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int vul_func(char *str)
{
    char buffer[50];        // 50바이트짜리 버퍼
    strcpy(buffer, str);    // ① ← Buffer overflow 문제!
    return 1;
}

int main(int argc, char **argv)
{
    char str[240];
    FILE *badfile;

    badfile = fopen("badfile", "r");       // 파일 열기
    fread(str, sizeof(char), 200, badfile); // 200바이트 읽기
    vul_func(str);                          // 취약 함수 호출

    printf("Returned Properly\n");
    return 1;
}
