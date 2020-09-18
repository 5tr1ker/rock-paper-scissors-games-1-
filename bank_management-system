#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data {
	char accountData[20];
	int accountMoney;
	struct data* link;
}data;

typedef struct {
	data *head;
}linkedlist;

linkedlist* NullLinkedList() {
	linkedlist* L;
	L = (linkedlist*)malloc(sizeof(linkedlist));
	L->head = NULL;
	return L;
}

void delete(linkedlist* L, data* p) {
	data* pre;
	if (L ->head->link == NULL) {
				free(L->head);
				L->head = NULL;
				printf("해당 계좌를 제거했습니다.\n");
				return;
			}
	else if (p == NULL) 
	{ 
		printf("현재 모든 계좌가 없습니다..\n"); return;
	}
			else {
				pre = L->head;
				while (pre->link != p) {
					pre = pre->link;
				}
				pre->link = p->link;
				free(p);
				printf("해당 계좌를 제거했습니다.\n"); 
			}
}

void accountprint(linkedlist* L) {
	data* p;
	p = L->head;
	while (p != NULL) {
		printf("Data :", p->accountData, "\tMoney :", p->accountMoney, "\n");
		p = p->link;
	}
}

void creatFirstAccount(linkedlist* L, data* p,char *Data, int Money) {
	data *node;
	node = (data *)malloc(sizeof(data));
	if (p == NULL) {
		strcpy(node->accountData, Data);
		node->accountMoney = Money;
		node->link = L->head;
		L->head = node;
	}
	else printf("해당 이름의 계좌는 이미 존재합니다...\n");
}

void changename(linkedlist* L, data* p, char *data) {
	if (p != NULL) { 
		strcpy(p->accountData, data); printf("계좌이름을 바꾸었습니다.\n"); 
	}
	else printf("계좌를 찾을 수 없습니다.");
}

void sendmoney(linkedlist* L, data* p, data* p2, int Money) {
	int dex;
	if (p != NULL) {
		if (p->accountMoney < Money) { 
			printf("해당계좌의 금액이 부족합니다.  잔액 :: %d\n", p->accountMoney);
		}
		else {
			p->accountMoney -= Money; dex = Money;
			p2->accountMoney += dex; printf("%s 님이 %s 님에게 %d 달러를 입금했습니다 \n", p->accountData, p2->accountData, dex);
		}
	}
	else printf("해당계좌를 찾을 수 없습니다.");
}

void Withdrawal(linkedlist* L ,data* p , int Money) {
	if (p != NULL) {
		if (p->accountMoney < Money) {
			printf("해당 계좌 잔액이 부족합니다 \t 잔액 : %d", p->accountMoney);
		}
		else { 
		p->accountMoney -= Money; 
		printf("%s 계좌에서 %d 의 금액을 출금했습니다", p->accountData, Money); }
	}
	else printf("해당계좌를 찾을 수 없습니다.");
}

void printf_account(linkedlist* L) {
	data* node;
	node = L->head;
	while (node != NULL) {
		printf("\t이름:%s\t 잔액: %d\n", &node->accountData, node->accountMoney);
		node = node->link;
	}
	node = L->head;
}

void print_oneAcount(linkedlist* L ,data* p) {
	if (p != NULL) 
		printf("\t이름:%s\t 잔액: %d\n", &p->accountData, p->accountMoney);
	else printf("해당 계좌를 찾을 수 없습니다");
}


void deposit(linkedlist* L,data* p, int Money) {
	if (p != NULL) {
		p->accountMoney += Money;
		printf("%s 계좌로 %d 달러가 입금됩니다.\t총 잔액:: %d", p->accountData, Money, p->accountMoney);
	}
	else printf("해당계좌를 찾을 수 없습니다.");
}



data* search(linkedlist* L, char* Data) {
	data* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->accountData, Data) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

int main() {
	linkedlist *L;
	data* p;
	data* p2;
	L = NullLinkedList();
		int choice, Money;
		char change[20] , send[20] , Data[20];
	while (1) {
		printf("\n");
		printf("은행 관리 프로그램\n");
		printf("원하시는 메뉴를 입력해주세요 \n");
		printf("1. 계좌 생성\n");
		printf("2. 계좌 정보 변경\n");
		printf("3. 다른 계좌로 전송\n");
		printf("4. 계좌 지우기\n");
		printf("5. 전체 계좌 보기\n");
		printf("6. 계좌 출금\n");
		printf("7. 계좌 입금\n");
		printf("8. 단일 계좌 보기\n");
		printf("9. 종료\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("계좌의 이름을 입력해주세요. 계좌설립시 2000달러의 지원을 해드립니다.\n");
			scanf("%s", &Data);
			p = search(L, Data);
			creatFirstAccount(L, p ,Data, 2000);
			break;
		case 2:
			printf("계좌 이름을 변경하기 위해 , 바꾸고자 하는 계좌의 이름 , 변경하고자 하는 이름을 입력해주세요.\n");
			scanf("%s %s", &Data, &change);
			p = search(L , Data); 
			changename(L, p , change);
			break;
		case 3:
			printf("전송할 계좌 이름과 받는 사람의 계좌 이름 , 전송할 금액을 입력해주세요\n");
			scanf("%s %s %d", &Data, &send, &Money);
			p = search(L, Data); p2 = search(L, send); 
			sendmoney(L, p, p2, Money);
			break;
		case 4:
			printf("지우실 계좌 이름을 입력해주세요.");
			scanf("%s", &Data);
			p = search(L, Data); 
			delete(L, p);
			break;
		case 5:
			printf("현재 개설되어있는 모든 계좌를 출력합니다.\n\n");
			printf_account(L);
			break;
		case 6:
			printf("출금하실 계좌와 금액을 입력해주세요\n");
			scanf("%s %d", &Data, &Money); 
			p = search(L, Data);
			Withdrawal(L, p, Money);
			break;
		case 7:
			printf("입금하실 계좌와 금액을 입력해주세요\n");
			scanf("%s %d", &Data, &Money);
			p = search(L , Data); 
			deposit(L, p, Money);
			break;
		case 8:
			printf("확인하실 계좌를 입력해주세요");
			scanf("%s", &Data); 
			p = search(L,Data); 
			print_oneAcount(L, p);
			break;
		case 9:
			exit(1); break;
		}
	}
}
