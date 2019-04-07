#include <stdio.h>
#include <stdlib.h>

int ran;
int ham(void);
int main()
{
	ran = ham();
	printf("컴퓨터가 무작위로 선택합니다... \n 1. 가위 2. 바위 3. 보 \n 컴퓨터가 (%d)를 선택했습니다",  ran );
	return 0;
}
int ham(void)
{
	srand(time(NULL));
	ran = rand() % ((3 - 1) + 1) + 1;
	return ran;
}