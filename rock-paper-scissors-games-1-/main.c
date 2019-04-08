#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice;					 // 사용자 선택 값
int rock_t, scis_t, paper_t = 1; // total
int rock_w, scis_w, paper_w = 1; // win rate
int ran, player;             // 컴퓨터가 낸 값, 플레이어가 선택한 값
void ran_games_values();     // 컴퓨터가 낸 값을 랜덤으로 산출
void game_result(int x);     // 게임 결과
void games_();				 // 게임.
void checking_winning_rate(); //승률 확인
void statis();				  //통계
rock_t = 1;
rock_w = 1;
scis_t = 1;
scis_w = 1;
int main()
{
	while (1)
	{
		do
		{
			puts("+--------------------------------+");
			puts("|  >rock-scissors-paper-games<   |");
			puts("+--------------------------------+");
			puts(" 1 . games starts");
			puts(" 2 . checking winning rate");
			puts(" 3 . statistics");
			puts(" 4 . exit");
			printf(" choice your decision :");
			scanf("%d", &choice);
		} while (choice < 1 || choice > 4);

		if (choice == 1)
		{
			games_();
		}
		if (choice == 2)
		{
			checking_winning_rate();
		}
		if (choice == 3)
		{
			statis();
		}
		if (choice == 4)
			break;
	}
}

void games_()			 // 표시까지 함수 games_ 범위
{
	srand(time(NULL));
	ran_games_values();
	printf("컴퓨터가 무작위로 선택합니다... \n\n 0. 가위 1. 바위 2. 보 \n");
	printf("플레이어가 낼 수를 입력해주세요... \n 범위 외의 값은 재입력을 요구합니다.:");

	do
	{
		scanf("%d", &player);
	}
	while (player < 0 || player > 2);
	game_result(player);
}

void ran_games_values()
{
	ran = rand() % 3;
}

void game_result(int x)
{
	if ((x == 0 && ran == 1) || (x == 1 && ran == 2) || (x == 2 && ran == 0))
	{
		if (x == 0)
		{
			scis_t++;
		}
		else if (x == 1)
		{
			rock_t++;
		}
		else
		{
			paper_t++;
		}

		printf("플레이어가 패배했습니다...\n");
	}
	else if ((x == 0 && ran == 2) || (x == 1 && ran == 0) || (x == 2 && ran == 1))
	{
		if (x == 0)
		{
			scis_t++;
			scis_w++;

		}
		else if (x == 1)
		{
			rock_t++;
			rock_w++;

		}
		else {
			paper_t++;
			paper_w++;
		}

		printf("플레이어가 이겼습니다...\n");
	}
	else if (x == ran)
	{
		printf("비겼습니다...\n");
	}
}								// 함수 game_ 종료

void checking_winning_rate()
{
	puts("your winning rate");
	printf("1 . Rock_winning_rate : %d%%\n", (rock_w / rock_t)*100);
	printf("2 . scissors_winning_rate : %d%%\n", (scis_w / scis_t)*100);
	printf("3 . paper_winning_rate : %d%%\n", (paper_w / paper_t) * 100);
	getch();
}

void statis()
{
	puts("total statis");
	printf("1 . Rock = *total = %d games / %d wins / %d defeat\n", rock_t-1 , rock_w-1 , rock_t - rock_w);
	printf("2 . Scissors = *total = %d games / %d wins / %d defeat\n", scis_t-1 , scis_w-1 , scis_t - scis_w);
	printf("3 . Papers = *total = %d games / %d wins / %d defeat\n", paper_t-1 , paper_w-1 , paper_t - paper_w);
}