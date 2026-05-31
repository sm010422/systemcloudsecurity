/* bof_target.c */
#include <stdio.h>

// 본인 학번의 맨 마지막 두자리 숫자에 50을 더한 값을 BUFFER_SIZE로 사용
// 예1) 60201234 라면 84를 BUFFER_SIZE로 사용
// 예2) 60201200 라면 50을 BUFFER_SIZE로 사용
#define BUFFER_SIZE 136

int func1() {
	printf("func1() executed\n");
	return -1;
}

int func2() {
	printf("BoF succedded!\n");
	return 1;
}

int main1() {
	char buffer[BUFFER_SIZE];
	scanf("%s", buffer);
	func1();
	return 1;
}

void main() {
	main1();
}
