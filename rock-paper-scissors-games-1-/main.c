#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran, player;
void ran_games_values();
void game_result(int x);
int main()
{
	srand(time(NULL));
	ran_games_values();
	printf("컴퓨터가 무작위로 선택합니다... \n\n 0. 가위 1. 바위 2. 보 \n");

	printf("플레이어가 낼 수를 입력해주세요 :");
	scanf("%d", &player);
	game_result(player);
	return 0;
}
void ran_games_values()
{
	ran = rand() % 3;
}
void game_result(int x)
{
	if ((x == 0 && ran == 1) || (x == 1 && ran == 2) || (x == 2 && ran == 0))
	{
		printf("플레이어가 패배했습니다...");
	}
	else if (x == ran)
	{
		printf("비겼습니다...");
	}
	else
		printf("플레이어가 이겼습니다...");
}