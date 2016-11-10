#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef char element;
typedef struct DlistNode {
	int line;
	element day[200];
	struct DlistNode *prev;
	struct DlistNode *next;
} DlistNode;


void printList(DlistNode* p)
{ // p는 headnode (pDays)
	DlistNode *tmp = p->next;
	printf("\n연결리스트 출력 >>> ");
	while (tmp != p) {
		printf("< %s >", tmp->day);
		tmp = tmp->next;
	}
	printf("\n------------------------------------\n\n");
}

// before : 선행 노드
// new_node : 삽입될 노드 
void dinsert_node(DlistNode *before, DlistNode *new_node)
{
	new_node->prev = before;
	new_node->next = before->next;
	before->next->prev = new_node;
	before->next = new_node;
}

// phead : 헤드 포인터에 대한 포인터 
// removed: 삭제될 노드 
void dremove_node(DlistNode *phead_node, DlistNode *removed)
{
	if (removed == phead_node) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}

DlistNode *search(DlistNode *head, char x[])
{
	DlistNode *p = head->next;
	while (p != head){
		if (strcmp(p->day, x) == 0) return p;  // 탐색 성공
		p = p->next;
	}
	return p;  // 탐색 실패일 경우 NULL 반환
}

void main()
{
	DlistNode *pDays, *new_node, *before, *remove;

	char select;
	char input[200];
	char where[200];

	pDays = (DlistNode*)malloc(sizeof(DlistNode));
	pDays->next = pDays;
	pDays->prev = pDays;

	while (true){
		printf("'a' : Add \n");
		printf("'r' : Remove \n");
		printf("'e' : Exit \n");
		printf("Input Select >>> ");
		scanf("%c", &select);
		fflush(stdin);
		switch (select){
		case 'a': 
			new_node = (DlistNode *)malloc(sizeof(DlistNode));
			printf("Input String >>> ");
			fgets(input, sizeof(input), stdin);
			input[strlen(input) - 1] = '\0';
			//scanf("%s", &input);
			strcpy(new_node->day, input);
			new_node->next = NULL;
			new_node->prev = NULL;

			if (pDays->next == pDays){
				dinsert_node(pDays, new_node);
			} else {
				printf("Input where? (Input String) >>> ");
				fgets(where, sizeof(where), stdin);
				where[strlen(where) - 1] = '\0';
				//scanf("%s", &input);
				before = search(pDays, where);
				dinsert_node(before, new_node);
			}
			printList(pDays);
			break;

		case 'r': 
			printf("Remove what? (Input String) >>> ");
			fgets(input, sizeof(input), stdin);
			input[strlen(input) - 1] = '\0';
			//scanf("%s", &input);
			remove = search(pDays, input);
			if (remove == NULL){
				break;
			}
			else {
				dremove_node(pDays, remove);
				printList(pDays);
				break;
			}

		case 'e': exit(true);  break;
		default: break;
		}
		fflush(stdin);
	}