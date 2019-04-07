#include <stdio.h>
#include <stdlib.h>

int ran;
void ran_games_values();
int main()
{
	srand(time(NULL));
	ran_games_values();
	printf("컴퓨터가 무작위로 선택합니다... \n 0. 가위 1. 바위 2. 보 \n 컴퓨터가 (%d)를 선택했습니다",  ran );
	return 0;
}
void ran_games_values()
{
	ran = rand() % 3;
}