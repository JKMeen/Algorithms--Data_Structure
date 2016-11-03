//연결리스트 pDays={월,화,수,목,금, 토, 일}

#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef char element;
typedef struct ListNode { 
	element day[3];
	struct ListNode *link;   
} ListNode; 


void printList( ListNode* p )
{
	ListNode *tmp = p->link; // p부터가 아닌 p->link부터 시작해야한다.
	printf("연결리스트 출력:");
	while( tmp!= NULL ) {
		printf(" %s ", tmp->day );
		tmp = tmp->link;
	}
	printf("\n");
}

// phead: 리스트의 헤드 포인터의 포인터
// before : 선행 노드
// new_node : 삽입될 노드 
void insert_node( ListNode *before, ListNode *new_node)
{	// if문이 필요없어짐
	new_node->link = before->link;
	before->link = new_node;
}

ListNode *search(ListNode *head, char x[])
{
	ListNode *p = head->link;
	while (p != NULL){
		if (strcmp(p->day, x) == 0) return p;  // 탐색 성공
		p = p->link;
	}
	return p;  // 탐색 실패일 경우 NULL 반환
}

// phead : 헤드 포인터에 대한 포인터 
// before: 삭제될 노드의 선행 노드
// removed: 삭제될 노드 
void remove_node(ListNode *before, ListNode *removed)
{
	before->link = removed->link;
	free(removed);
}

int main()
{
	ListNode *pDays; //

	pDays = (ListNode*)malloc(sizeof(ListNode));
	pDays->link = NULL;

	ListNode *new_node, *before, *remove;

	// 메모리 할당
	/*월*/
	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "월");  // c에서는 스트링이 없으므로 strcpy(스트링카피)를 사용
	new_node->link = NULL;
	insert_node( pDays, new_node);
	
	/*금*/
	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "금");
	new_node->link = NULL;
	//search
	before = search( pDays, "월"); // 월요일을 찾아서 before에 넣어줌
	insert_node( before, new_node);

	/*화*/
	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "화");
	new_node->link = NULL;
	before = search(pDays, "월");
	insert_node(before, new_node);

	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "수");
	new_node->link = NULL;
	before = search(pDays, "화");
	insert_node(before, new_node);
	
	printList(pDays);

	printf("삭제 후 결과\n");
	remove = search(pDays, "수");
	before = search(pDays, "화");
	remove_node(before, remove);

	printList( pDays );
	return 0;
}