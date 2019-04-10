#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice;					 // 사용자 선택 값
float rock_t, scis_t, paper_t; // total
float rock_w, scis_w, paper_w; // win rate
int ran, player;             // 컴퓨터가 낸 값, 플레이어가 선택한 값
void ran_games_values();     // 컴퓨터가 낸 값을 랜덤으로 산출
void game_result(int x);     // 게임 결과
void games_();				 // 게임.
void checking_winning_rate(); //승률 확인
void statis();				  //통계
void how_to_play();           //헬프
int coin = 20;					//코인값
int coin2 = 0;						//베팅 값
int MAX_coin = 20;                //코인 최댓값
int com, pla = 0;                  //3선승제 계산
void result_();                    // 포인트 합산
int i;                             // 게임수
com = 0;
rock_t = 1.0;
rock_w = 1.0;
scis_t = 1.0;
scis_w = 1.0;
paper_t = 1.0;
paper_w = 1.0;
int main()
{
	while (1)
	{
		do
		{
			puts("+--------------------------------+");
			puts("|  >rock-scissors-paper-games<   |");
		    printf("|        You have :   %d COIN  \n" , coin);
			printf("|     MAX_coin = %d             \n" , MAX_coin);
			puts("+--------------------------------+");
			puts(" 1 . games starts");
			puts(" 2 . checking winning rate");
			puts(" 3 . statistics");
			puts(" 4 . how to play");
			puts(" 5 . exit");
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
		{
			how_to_play();
		}
		if (choice == 5)
			break;
	}

}

void games_()			 // 표시까지 함수 games_ 범위
{
	com = 0;
	pla = 0;
	printf("베팅하실 코인을 입력해주세요 승리시 2배 , 패배시 코인을 잃습니다==");
	scanf("%d", &coin2);
	coin -= coin2;
	for (i = 0; i < 3 && com < 2 && pla < 2 ; i++)
	{
		printf("[%d 번째 게임 컴퓨터 %d승 || 사용자 %d승 (2선승)\n" , i+1 , com , pla);
		printf("컴퓨터가 무작위로 선택합니다...      0. 가위 1. 바위 2. 보 \n\n");
		srand(time(NULL));
		ran_games_values();
		printf("플레이어가 낼 수를 입력해주세요... \n 범위 외의 값은 재입력을 요구합니다.:");

		do
		{
			scanf("%d", &player);
		} while (player < 0 || player > 2);
		game_result(player);
		result_();
	}
	if (coin <= 0)
	{
		printf("남은 코인을 전부 잃어 프로그램을 종료합니다\n");
		getch();
		exit(1);
	}
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
		com++;
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
		pla++;
	}
	else if (x == ran)
	{
		printf("비겼습니다...\n");
		i--;
	}
}								// 함수 game_ 종료

void checking_winning_rate()
{
	printf("\n");
	puts("your winning rate");
	if (rock_t != 1)
		printf("1 . Rock_winning_rate : %3.2f%%\n", ((rock_w - 1) / (rock_t - 1)) * 100);
	else
		printf("1. 1 . Rock_winning_rate : 100.00%%\n");
	if (scis_t != 1)
		printf("2 . scissors_winning_rate : %3.2f%%\n", ((scis_w - 1) / (scis_t - 1)) * 100);
	else
		printf("2.scissors_winning_rate : 100.00%%\n");
	if (paper_t != 1)
		printf("3 . paper_winning_rate : %3.2f%%\n", ((paper_w - 1) / (paper_t - 1)) * 100);
	else
		printf("3 . paper_winning_rate : 100.00%%\n");
	getch();
}

void statis()
{
	puts("total statis");
	printf("1 . Rock = *total = %1.0f games / %1.0f wins / %1.0f defeat\n", rock_t-1 , rock_w-1 , rock_t - rock_w);
	printf("2 . Scissors = *total = %1.0f games / %1.0f wins / %1.0f defeat\n", scis_t-1 , scis_w-1 , scis_t - scis_w);
	printf("3 . Papers = *total = %1.0f games / %1.0f wins / %1.0f defeat\n", paper_t-1 , paper_w-1 , paper_t - paper_w);
}

void how_to_play()
{
	printf("+----------------------------------+\n");
	printf("컴퓨터와 가위 바위 보를 진행하게됩니다.\n");
	printf("코인은 베팅할수도있고 , 안할수도 있습니다.\n");
	printf("코인이 0이되면 게임은 종료가 됩니다.\n");
	printf("프로그램은 , 저장 , 불러오기 기능이 있습니다.\n");
}

void result_()
{
	if (com == 2)
	{
		printf("플레이어의 패배로 , 베팅하신 %d 코인은 전부 잃습니다\n\n", coin2);
		coin2 = 0;
	}
	else if (pla == 2)
	{
		printf("플레이어의 승리로 , 코인 %d 를 두배로 돌려받습니다\n\n", coin2);
		coin += (coin2 * 2);
	}
	if (MAX_coin < coin)
		MAX_coin = coin;
}